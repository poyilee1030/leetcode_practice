#pragma once

#include <iostream>
#include <vector>

using namespace std;


class Interval {
public:
	int start, end;
	Interval(int start, int end) {
		this->start = start;
		this->end = end;
	}
};

static bool cmp(const Interval& a, const Interval& b) {
	return a.start < b.start;
}


class _0919_lintcode_meeting_rooms_ii
{
public:
	/*
	int minMeetingRooms(vector<Interval>& intervals) {
		if (intervals.size() == 0)
			return 0;
		sort(intervals.begin(), intervals.end(), cmp);
		int res = 1;
		vector<Interval> room = { intervals[0] };
		for (int i = 1; i < intervals.size(); i++) {
			bool have_room = false;
			for (int j = 0; j < room.size(); j++) {
				if (intervals[i].start >= room[j].end) {
					room[j] = intervals[i];
					have_room = true;
					break;
				}
			}
			if (!have_room) {
				room.push_back(intervals[i]);
			}
			res = max(res, (int)room.size());
		}
		return res;
	}
	*/
	
	/*
	int minMeetingRooms(vector<Interval>& intervals) {
		vector<int> start_list;
		vector<int> end_list;
		for (auto tmp : intervals) {
			start_list.push_back(tmp.start);
			end_list.push_back(tmp.end);
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

	int minMeetingRooms(vector<Interval>& intervals) {
		// sort intervals by start time
		sort(intervals.begin(), intervals.end(), cmp);

		// min heap to track min end time of merged intervals
		priority_queue<int, vector<int>, greater<int>> pq;
		pq.push(intervals[0].end);

		for (int i = 1; i < intervals.size(); i++) {
			// compare curr start w/ earliest end time, if no overlap then pop
			if (intervals[i].start >= pq.top()) {
				pq.pop();
			}
			// add new room (will replace/be same size if above was true)
			pq.push(intervals[i].end);
		}

		return pq.size();
	}

	void do_test(_0919_lintcode_meeting_rooms_ii* sol) {
		vector<Interval> intervals;
		int ret;

		intervals = { Interval(0, 30), Interval(5, 10), Interval(15, 20) };
		ret = sol->minMeetingRooms(intervals);
		cout << ret << endl;
		// Output : 2

		intervals = { Interval(7, 10), Interval(2, 4) };
		ret = sol->minMeetingRooms(intervals);
		cout << ret << endl;
		// Output : 1

		intervals = { Interval(13, 15), Interval(1, 13), Interval(6, 9) };
		ret = sol->minMeetingRooms(intervals);
		cout << ret << endl;
		// Output : 2
	}
};
