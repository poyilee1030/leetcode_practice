#pragma once

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
	Given array of time intervals, determine min # of meeting rooms required
	Ex. intervals = [[0,30],[5,10],[15,20]] -> 2

	Min heap for earliest end times, most overlap will be heap size

	Time: O(n log n)
	Space: O(n)
*/

class _0253_meeting_rooms_ii
{
public:
	int minMeetingRooms(vector<vector<int>>& intervals) {
		// sort intervals by start time
		sort(intervals.begin(), intervals.end());

		// min heap to track min end time of merged intervals
		priority_queue<int, vector<int>, greater<int>> pq;
		pq.push(intervals[0][1]);

		for (int i = 1; i < intervals.size(); i++) {
			// compare curr start w/ earliest end time, if no overlap then pop
			if (intervals[i][0] >= pq.top()) {
				pq.pop();
			}
			// add new room (will replace/be same size if above was true)
			pq.push(intervals[i][1]);
		}

		return pq.size();
	}

	/*
	int minMeetingRooms(vector<vector<int>>& intervals) {
		vector<int> start_list;
		vector<int> end_list;
		for (auto tmp : intervals) {
			start_list.push_back(tmp[0]);
			end_list.push_back(tmp[1]);
		}

		sort(start_list.begin(), start_list.end());
		sort(end_list.begin(), end_list.end());

		int s = 0;
		int e = 0;
		int count = 0;
		int maxcnt = 0;
		while (s < start_list.size()) {
			if (start_list[s] < end_list[e]) {
				count++;
				s++;
				maxcnt = max(count, maxcnt);
			}
			else {
				count--;
				e++;
				maxcnt = max(count, maxcnt);
			}
		}
		return maxcnt;
	}
	*/
	

	void do_test(_0253_meeting_rooms_ii* sol) {
		vector<vector<int>> intervals;
		int ret;

		intervals = { {0, 30}, {5, 10}, {15, 20} };
		ret = sol->minMeetingRooms(intervals);
		cout << ret << endl;
		// Output : 2
		
		intervals = { {7, 10}, {2, 4} };
		ret = sol->minMeetingRooms(intervals);
		cout << ret << endl;
		// Output : 1

		intervals = { {13, 15}, {1, 13}, {6, 9} };
		ret = sol->minMeetingRooms(intervals);
		cout << ret << endl;
		// Output : 2
	}
};
