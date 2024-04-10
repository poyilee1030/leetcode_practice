#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;


class _0046_permutations
{
public:
	vector<vector<int>> permute(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> ans;
		vector<bool> visit(n, false);
		vector<int> curr;
		dfs(nums, curr, visit, ans);
		return ans;
	}

	void dfs(vector<int>& nums, vector<int>& curr, vector<bool>& visit, vector<vector<int>>& ans) {
		if (curr.size() == nums.size()) {
			ans.push_back(curr);
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (visit[i])
				continue;
			else {
				visit[i] = true;
				curr.push_back(nums[i]);
				dfs(nums, curr, visit, ans);
				visit[i] = false;
				curr.pop_back();
			}
		}
	}

	/*
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> curr = {};
		backtrack(nums, curr, result);
		return result;
	}

	void backtrack(vector<int>& nums, vector<int>& curr, vector<vector<int>>& result) {
		if (curr.size() == nums.size()) {
			result.push_back(curr);
			return;
		}

		for (int num : nums) {
			if (find(curr.begin(), curr.end(), num) == curr.end()) {
				curr.push_back(num);
				backtrack(nums, curr, result);
				curr.pop_back();
			}
		}
	}
	*/

	void do_test(_0046_permutations* sol)
	{
		vector<int> nums;
		vector<vector<int>> ret;

		nums = { 1, 2, 3 };
		ret = sol->permute(nums);
		print_vector_of_vector(ret);
		//Output : [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
		
		nums = { 0, 1 };
		ret = sol->permute(nums);
		print_vector_of_vector(ret);
		//Output : [[0, 1], [1, 0]]
		
		nums = { 1 };
		ret = sol->permute(nums);
		print_vector_of_vector(ret);
		//Output : [[1]]
	}
};
