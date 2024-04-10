#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;


class _0047_permutations_ii
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        unordered_map<int, int> freq;
        for (int n : nums)
            freq[n]++;

        vector<int> curr;
        dfs(freq, curr, n, ans);

        return ans;
    }

    void dfs(unordered_map<int, int>& freq, vector<int> curr, int n, vector<vector<int>>& ans) {
        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        for (auto it = freq.begin(); it != freq.end(); it++) {
            if (it->second == 0) {
                continue;
            }

            curr.push_back(it->first);
            it->second -= 1;
            dfs(freq, curr, n, ans);
            it->second += 1;
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
