#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class _0210_course_schedule_ii
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> prereq;
        // build adjacency list of prereqs
        for (int i = 0; i < prerequisites.size(); i++) {
            prereq[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        unordered_set<int> visit;
        unordered_set<int> cycle;

        vector<int> result;
        for (int course = 0; course < numCourses; course++) {
            if (!dfs(course, prereq, visit, cycle, result)) {
                return {};
            }
        }
        return result;
    }

    // a course has 3 possible states:
    // visited -> course added to result
    // visiting -> course not added to result, but added to cycle
    // unvisited -> course not added to result or cycle
    bool dfs(int course, unordered_map<int, vector<int>>& prereq, unordered_set<int>& visit,
        unordered_set<int>& cycle, vector<int>& result) {

        if (cycle.find(course) != cycle.end()) {
            return false;
        }
        if (visit.find(course) != visit.end()) {
            return true;
        }
        cycle.insert(course);
        for (int i = 0; i < prereq[course].size(); i++) {
            int pre = prereq[course][i];
            if (!dfs(pre, prereq, visit, cycle, result)) {
                return false;
            }
        }
        cycle.erase(course);
        visit.insert(course);
        result.push_back(course);
        return true;
    }

	void do_test(_0210_course_schedule_ii* sol)
	{
		int numCourses1 = 2;
		vector<vector<int>> prerequisites1 = { {1, 0} };
		vector<int> ret1 = sol->findOrder(numCourses1, prerequisites1);
		print_res(ret1);
		/*
		Output: [0,1]
		Explanation: There are a total of 2 courses to take. 
		To take course 1 you should have finished course 0. 
		So the correct course order is [0,1].
		*/

		int numCourses2 = 4; 
		vector<vector<int>> prerequisites2 = { {1, 0}, {2, 0}, {3, 1}, {3, 2} };
		vector<int> ret2 = sol->findOrder(numCourses2, prerequisites2);
		print_res(ret2);
		/*
		Output: [0,2,1,3]
		Explanation: There are a total of 4 courses to take. 
		To take course 3 you should have finished both courses 1 and 2. 
		Both courses 1 and 2 should be taken after you finished course 0.
		So one correct course order is [0,1,2,3]. 
		Another correct ordering is [0,2,1,3].
		*/
	}

	void print_res(vector<int> res)
	{
		cout << "[";
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i];
			if (i < res.size() - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}
};
