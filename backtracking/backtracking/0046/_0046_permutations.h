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
		vector<bool> visited(n, false);
		vector<int> curr;
		dfs(nums, curr, visited, ans);
		return ans;
	}

	void dfs(vector<int>& nums, vector<int>& curr, vector<bool>& visited, vector<vector<int>>& ans) {
		if (curr.size() == nums.size()) {
			ans.push_back(curr);
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (visited[i])
				continue;

			visited[i] = true;
			curr.push_back(nums[i]);
			dfs(nums, curr, visited, ans);
			visited[i] = false;
			curr.pop_back();
		}
	}

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
