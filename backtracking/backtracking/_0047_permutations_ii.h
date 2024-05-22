#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;


class _0047_permutations_ii
{
public:
    // 去重套路
    // 1. sort
    // 2. if (j != start && nums[j] == nums[j - 1])

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> visited(n, 0);
        vector<int> curr;
        sort(nums.begin(), nums.end()); // <-- 新增
        dfs(nums, visited, curr, ans);
        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& visited, vector<int>& curr, vector<vector<int>>& ans) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])
                continue;
            if (i != 0 && nums[i] == nums[i - 1] && !visited[i - 1]) // <--新增
                continue;
            curr.push_back(nums[i]);
            visited[i] = 1;
            dfs(nums, visited, curr, ans);
            visited[i] = 0;
            curr.pop_back();
        }
    }

	void do_test(_0047_permutations_ii* sol) {
        vector<int> nums;
        vector<vector<int>> ret;

        nums = { 1, 1, 2 };
        ret = sol->permuteUnique(nums);
        print_vector_of_vector(ret);
        // Output : [[1, 1, 2], [1, 2, 1], [2, 1, 1]]

        nums = { 1, 2, 3 };
        ret = sol->permuteUnique(nums);
        print_vector_of_vector(ret);
        // Output : [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
	}
};
