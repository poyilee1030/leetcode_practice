#pragma once

#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;


class _0260_single_number_iii
{
public:
    /* 
    1. x&(x-1)：　表示unset the rightmost set bit
    
        例如
             88 = 01011000
             87 = 01010111
                      ↓ 對於88來說，最右邊的1被消掉了
        88 & 87 = 01010000

    2. x^(x&(x-1))：　表示只保留 the rightmost set bit

    例如
        88 & 87 = 01010000
             88 = 01011000
                      ↑ 對於88來說，只留下最右邊的1
        
    3. log2(x^(x&(x-1)))：　表示the rightmost set bit的位置
        好像沒用到這個特性?

    */
    vector<int> singleNumber(vector<int>& nums) {
        int s = 0;
        for (auto n : nums)
            s = s ^ n;  // i.e. a^b

        //int t = s ^ (s & (s - 1)); // only keep the rightmost set bit

        int u = 0;
        for (int i = 0; i < 32; i++) {
            if ((s >> i) & 1) {
                u = 1 << i;
                break;
            }
        }
        //cout << "t = " << t << endl;
        //cout << "u = " << u << endl;

        int a = 0, b = 0;
        for (auto n : nums) {
            if (n & u)
                a = a ^ n;
            else
                b = b ^ n;
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

        nums = { 1, 1, 0, -2147483648 };
        ret = sol->singleNumber(nums);
        print_vector(ret);
        // Output : [-2147483648,0]
	}
};
