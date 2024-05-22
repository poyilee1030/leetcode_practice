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

	// style 1: neetcode �g�k�A�H���D�ӻ����n�z��
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

	// style 2: ���g�k������ҪO�A�I�_�ӫ�i�H���L��
	// ���M���D�����n�z�ѡA���A�Ωʸ��s�x
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
