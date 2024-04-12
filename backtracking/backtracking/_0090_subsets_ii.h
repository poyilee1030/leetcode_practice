#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;


class _0090_subsets_ii
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<vector<int>> ans;
        dfs(nums, 0, curr, ans);
        return ans;
    }

    // style 1
    void dfs(vector<int>& nums, int i, vector<int>& curr, vector<vector<int>>& result) {
        if (i >= nums.size()) {
            result.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        dfs(nums, i + 1, curr, result);
        curr.pop_back();
        while ((i + 1 < nums.size()) && (nums[i] == nums[i + 1]))
            i++;
        dfs(nums, i + 1, curr, result);
    }

    /* style 2
    void dfs(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& ans) {
        ans.push_back(curr);

        for (int j = start; j < nums.size(); j++) {
            if (j != start && nums[j] == nums[j - 1])
                continue;
            curr.push_back(nums[j]);
            dfs(nums, j + 1, curr, ans);
            curr.pop_back();
        }
    }
    */

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
