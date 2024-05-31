#pragma once

#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;


class _0260_single_number_iii
{
public:
    vector<int> singleNumber(vector<int>& nums) {
        long s = 0;
        for (auto n : nums) s = s ^ n;  // i.e. a^b
        int t = s ^ (s & (s - 1)); // only keep the rightmost set bit
        int a = 0, b = 0;
        for (auto n : nums)
        {
            if (n & t) a = a ^ n;
            else b = b ^ n;
        }
        return { a, b };
    }

	void do_test(_0260_single_number_iii* sol) {
        vector<int> nums;
        vector<int> ret;

        nums = { 1, 2, 1, 3, 2, 5 };
        ret = sol->singleNumber(nums);
        print_vector(ret);
        // Output : [3, 5]
        // Explanation : [5, 3] is also a valid answer.
        
        nums = { -1, 0 };
        ret = sol->singleNumber(nums);
        print_vector(ret);
        // Output : [-1, 0]

        nums = { 0, 1 };
        ret = sol->singleNumber(nums);
        print_vector(ret);
        // Output : [1, 0]
	}
};
