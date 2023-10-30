#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0252_meeting_rooms
{
public:
	bool canAttendMeetings(vector<vector<int>>& intervals) {
		return false;
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
