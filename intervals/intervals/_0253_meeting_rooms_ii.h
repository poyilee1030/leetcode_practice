#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0253_meeting_rooms_ii
{
public:
	int minMeetingRooms(vector<vector<int>>& intervals) {
		return 0;
	}

	void do_test(_0253_meeting_rooms_ii* sol) {
		vector<vector<int>> intervals1 = { {0, 30}, {5, 10}, {15, 20} };
		int ret1 = sol->minMeetingRooms(intervals1);
		cout << ret1 << endl;
		// Output : 2
		

		vector<vector<int>> intervals2 = { {7, 10}, {2, 4} };
		int ret2 = sol->minMeetingRooms(intervals2);
		cout << ret2 << endl;
		// Output : 1
	}
};
