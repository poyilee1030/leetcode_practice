#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "../utils.h"

using namespace std;


class _0090_subsets_ii
{
public:
    // �h���M��
    // 1. sort
    // 2. if (j > start && nums[j] == nums[j - 1])

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // �s�W
        dfs_style2(nums, 0, curr, ans);
        return ans;
    }

    // style 1: neetcode �g�k
    void dfs_style1(vector<int>& nums, int i, vector<int>& curr, vector<vector<int>>& result) {
        if (i >= nums.size()) {
            result.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        dfs_style1(nums, i + 1, curr, result);
        curr.pop_back();
        while ((i + 1 < nums.size()) && (nums[i] == nums[i + 1])) // �s�W
            i++;
        dfs_style1(nums, i + 1, curr, result);
    }

    // style 2: ���ˡA�[ if �� style1 �� while �n�z��
    void dfs_style2(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& ans) {
        
        ans.push_back(curr);
        for (int j = start; j < nums.size(); j++) {
            if (j > start && nums[j] == nums[j - 1]) // �s�W
                continue;
            curr.push_back(nums[j]);
            dfs_style2(nums, j + 1, curr, ans);
            curr.pop_back();
        }
    }

	void do_test(_0090_subsets_ii* sol) {
        vector<int> nums;
        vector<vector<int>> ret;
        
        nums = { 1, 2, 2 };
        ret = subsetsWithDup(nums);
        print_vector_of_vector(ret);
        // Output : [[], [1], [1,2], [1,2,2], [2], [2,2]]

        nums = { 0 };
        ret = subsetsWithDup(nums);
        print_vector_of_vector(ret);
        // Output : [[], [0]]
	}
};
