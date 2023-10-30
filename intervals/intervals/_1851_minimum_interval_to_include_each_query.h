#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _1851_minimum_interval_to_include_each_query
{
public:
	vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
		vector<int> q;
		return q;
	}

	void do_test(_1851_minimum_interval_to_include_each_query* sol) {
		vector<vector<int>> intervals1 = { {1, 4}, {2, 4}, {3, 6}, {4, 4} };
		vector<int> queries1 = { 2, 3, 4, 5 };
		vector<int> ret1 = sol->minInterval(intervals1, queries1);
		print_res(ret1);
		/*
		Output : [3, 3, 1, 4]
		Explanation : The queries are processed as follows :
		- Query = 2 : The interval[2, 4] is the smallest interval containing 2. The answer is 4 - 2 + 1 = 3.
		- Query = 3 : The interval[2, 4] is the smallest interval containing 3. The answer is 4 - 2 + 1 = 3.
		- Query = 4 : The interval[4, 4] is the smallest interval containing 4. The answer is 4 - 4 + 1 = 1.
		- Query = 5 : The interval[3, 6] is the smallest interval containing 5. The answer is 6 - 3 + 1 = 4.
		*/
		
		vector<vector<int>> intervals2 = { {2, 3}, {2, 5}, {1, 8}, {20, 25} };
		vector<int> queries2 = { 2, 19, 5, 22 };
		vector<int> ret2 = sol->minInterval(intervals2, queries2);
		print_res(ret2);
		/*
		Output : [2, -1, 4, 6]
		Explanation : The queries are processed as follows :
		- Query = 2 : The interval[2, 3] is the smallest interval containing 2. The answer is 3 - 2 + 1 = 2.
		- Query = 19 : None of the intervals contain 19. The answer is - 1.
		- Query = 5 : The interval[2, 5] is the smallest interval containing 5. The answer is 5 - 2 + 1 = 4.
		- Query = 22 : The interval[20, 25] is the smallest interval containing 22. The answer is 25 - 20 + 1 = 6.
		*/
	}

	void print_res(vector<int>& res) {
		cout << "[";
		for (int i = 0; i < res.size(); i++) {
			cout << res[i];
			if (i < res.size() - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}
};
