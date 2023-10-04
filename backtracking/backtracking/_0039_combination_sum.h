#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class _0039_combination_sum
{
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());

		vector<int> curr;
		vector<vector<int>> result;

		dfs(candidates, target, 0, 0, curr, result);
		return result;
	}

	void dfs(vector<int>& candidates, int target, int total, int i, vector<int>& curr, vector<vector<int>>& result) {
		if (total == target) {
			result.push_back(curr);
			return;
		}
		if (i >= candidates.size() || total > target) {
			return;
		}

		curr.push_back(candidates[i]);
		dfs(candidates, target, total + candidates[i], i, curr, result);
		curr.pop_back();
		dfs(candidates, target, total, i + 1, curr, result);
	}

	void do_test(_0039_combination_sum* sol)
	{
		vector<int> candidates1 = { 2, 3, 6, 7 }; 
		int target1 = 7;
		vector<vector<int>> ret1 = combinationSum(candidates1, target1);
		print_res(ret1);
		//Output : [[2, 2, 3], [7]]
		//Explanation :
		//2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
		//7 is a candidate, and 7 = 7.
		//These are the only two combinations.

		vector<int> candidates2 = {2, 3, 5};
		int target2 = 8;
		vector<vector<int>> ret2 = combinationSum(candidates2, target2);
		print_res(ret2);
		//Output : [[2, 2, 2, 2], [2, 3, 3], [3, 5]]

		vector<int> candidates3 = { 2 }; 
		int target3 = 1;
		vector<vector<int>> ret3 = combinationSum(candidates3, target3);
		print_res(ret3);
		//Output : []
	}

	void print_res(vector<vector<int>> res)
	{
		cout << "[";
		for (int i = 0; i < res.size(); ++i)
		{
			cout << "[";
			vector<int> oo = res[i];
			for (int j = 0; j < oo.size(); ++j)
			{
				cout << oo[j];
				if (j != oo.size() - 1)
					cout << ",";
			}
			cout << "]";
			if (i != res.size() - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}
};


