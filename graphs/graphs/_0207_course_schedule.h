#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class _0207_course_schedule
{
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // map each course to prereq list
        unordered_map<int, vector<int>> preMap;
        for (int i = 0; i < prerequisites.size(); i++) {
            preMap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        // all courses along current DFS path
        unordered_set<int> visited;

        for (int course = 0; course < numCourses; course++) {
            if (!dfs(course, preMap, visited)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int course, unordered_map<int, vector<int>>& preMap, unordered_set<int>& visited) {
        if (visited.find(course) != visited.end()) {
            return false;
        }
        if (preMap[course].empty()) {
            return true;
        }
        visited.insert(course);
        for (int i = 0; i < preMap[course].size(); i++) {
            int pre = preMap[course][i];
            if (!dfs(pre, preMap, visited)) {
                return false;
            }
        }
        visited.erase(course);
        preMap[course].clear();
        return true;
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
