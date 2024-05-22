#pragma once

#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;


class _0078_subsets
{
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> curr;
		vector<vector<int>> ans;
		dfs_style2(nums, 0, curr, ans);
		return ans;
	}

	// style 1: neetcode 寫法，以此題來說較好理解
	void dfs_style1(vector<int>& nums, int i, vector<int>& curr, vector<vector<int>>& ans) {
		if (i >= nums.size()) {
			ans.push_back(curr);
			return;
		}
		curr.push_back(nums[i]);
		dfs_style1(nums, i + 1, curr, ans);
		curr.pop_back();
		dfs_style1(nums, i + 1, curr, ans);
	}

	// style 2: 此寫法比較像模板，背起來後可以較無腦
	// 雖然此題較不好理解，但適用性較廣泛
	void dfs_style2(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& ans) {
		
		ans.push_back(curr);
		for (int j = start; j < nums.size(); j++) {
			curr.push_back(nums[j]);
			dfs_style2(nums, j + 1, curr, ans);
			curr.pop_back();
		}
	}
	
	void do_test(_0078_subsets* sol) {
		vector<int> nums;
		vector<vector<int>> ret;

		nums = { 1, 2, 3 };
		ret = subsets(nums);
		print_vector_of_vector(ret);
		//Output : [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
		
		nums = { 0 };
		ret = subsets(nums);
		print_vector_of_vector(ret);
		//Output : [[], [0]]
	}
};
