#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
	Given array of time intervals, determine if can attend all meetings
	Ex. intervals = [[0,30],[5,10],[15,20]] -> false

	Sort by start time, check adj meetings, if overlap return false

	Time: O(n log n)
	Space: O(1)
*/

class _0252_meeting_rooms
{
public:
	bool canAttendMeetings(vector<vector<int>>& intervals) {
		if (intervals.empty()) {
			return true;
		}

		sort(intervals.begin(), intervals.end());
		for (int i = 0; i < intervals.size() - 1; i++) {
			if (intervals[i][1] > intervals[i + 1][0]) {
				return false;
			}
		}
		return true;
	}

	void do_test(_0252_meeting_rooms* sol) {
		vector<vector<int>> intervals1 = { {0, 30}, {5, 10}, {15, 20} };
		bool ret1 = sol->canAttendMeetings(intervals1);
		cout << ret1 << endl;
		// Output : false
		
		vector<vector<int>> intervals2 = { {7, 10}, {2, 4} };
		bool ret2 = sol->canAttendMeetings(intervals2);
		cout << ret2 << endl;
		// Output : true
	}
};
