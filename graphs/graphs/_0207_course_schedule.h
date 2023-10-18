#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0207_course_schedule
{
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

	}

	void do_test(_0207_course_schedule* sol)
	{
		int numCourses1 = 2;
		vector<vector<int>> prerequisites1 = { {1, 0} };
		bool ret1 = sol->canFinish(numCourses1, prerequisites1);
		cout << ret1 << endl;
		/*
		Output : true
		Explanation : There are a total of 2 courses to take.
		To take course 1 you should have finished course 0.
		So it is possible.
		*/

		int numCourses2 = 2; 
		vector<vector<int>> prerequisites2 = { {1, 0}, {0, 1 } };
		bool ret2 = sol->canFinish(numCourses2, prerequisites2);
		cout << ret2 << endl;
		/*
		Output : false
		Explanation : There are a total of 2 courses to take.
		To take course 1 you should have finished course 0,
		and to take course 0 you should also have finished course 1.
		So it is impossible.
		*/
	}
};
