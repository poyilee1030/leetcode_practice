#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include "utils.h"

using namespace std;


class _0001_two_sum
{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp; // val -> index

        for (int i = 0; i < n; i++) {
            int compliment = target - nums[i];
            if (mp.find(compliment) != mp.end()) {
                return { mp[compliment], i };
            }
            mp.insert({ nums[i], i });
        }
        return {};
    }

    void do_test(_0001_two_sum *sol) {
        vector<int> nums;
        vector<int> ret;
        nums = { 2, 7, 11, 15 };
        ret = sol->twoSum(nums, 9);
        //Output: [0, 1]
        print_vector(ret);

        nums = { 3, 2, 4 };
        ret = sol->twoSum(nums, 6);
        //Output: [1, 2]
        print_vector(ret);

        nums = { 3, 3 };
        ret = sol->twoSum(nums, 6);
        //Output: [0, 1]
        print_vector(ret);
    }
};
