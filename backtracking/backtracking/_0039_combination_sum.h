#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;


class _0039_combination_sum
{
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> curr;
		vector<vector<int>> ans;
		sort(candidates.begin(), candidates.end());
		dfs_style2(candidates, target, 0, 0, curr, ans);
		return ans;
	}

	// style 1
	void dfs_style1(vector<int>& candidates, int target, int i, int total, vector<int>& curr, vector<vector<int>>& ans) {
		if (total == target) {
			ans.push_back(curr);
			return;
		}
		if (i >= candidates.size() || total > target) {
			return;
		}

		curr.push_back(candidates[i]);
		dfs_style1(candidates, target, i, total + candidates[i], curr, ans);
		curr.pop_back();
		dfs_style1(candidates, target, i + 1, total, curr, ans);
	}

	// style 2
	void dfs_style2(vector<int>& candidates, int target, int i, int total, vector<int>& curr, vector<vector<int>>& ans) {
		if (total == target) {
			ans.push_back(curr);
			return;
		}
		if (total > target)
			return;

		for (int j = i; j < candidates.size(); j++) {
			curr.push_back(candidates[j]);
			dfs_style2(candidates, target, j, total + candidates[j], curr, ans);
			curr.pop_back();
		}
	}

	void do_test(_0039_combination_sum* sol)
	{
		vector<int> candidates;
		vector<vector<int>> ret;

		candidates = { 2, 3, 6, 7 }; 
		ret = combinationSum(candidates, 7);
		print_vector_of_vector(ret);
		// Output : [[2, 2, 3], [7]]
		// Explanation :
		// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
		// 7 is a candidate, and 7 = 7.
		// These are the only two combinations.

		candidates = { 2, 3, 5 };
		ret = combinationSum(candidates, 8);
		print_vector_of_vector(ret);
		// Output : [[2, 2, 2, 2], [2, 3, 3], [3, 5]]

		candidates = { 2 }; 
		ret = combinationSum(candidates, 1);
		print_vector_of_vector(ret);
		// Output : []
	}
};
