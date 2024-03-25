#pragma once
#include <vector>
#include <iostream>
#include "utils.h"

using namespace std;


class _0238_product_of_array_except_self
{
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        int prefix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix = prefix * nums[i];
        }

        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] = result[i] * postfix;
            postfix = postfix * nums[i];
        }

        return result;
    }

    void do_test(_0238_product_of_array_except_self *sol) {
        vector<int> nums1 = { 1, 2, 3, 4 };
        vector<int> ret1 = sol->productExceptSelf(nums1);
        //Output: [24, 12, 8, 6]
        print_vector(ret1);

        vector<int> nums2 = { -1, 1, 0, -3, 3 };
        vector<int> ret2 = sol->productExceptSelf(nums2);
        //Output: [0, 0, 9, 0, 0]
        print_vector(ret2);
    }
};
