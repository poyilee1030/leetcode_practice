#pragma once

#include <iostream>

using namespace std;


class _0201_bitwise_and_of_numbers_range
{
public:
    int rangeBitwiseAnd(int left, int right) {
        
        while (right > left) {
            right &= (right - 1);
        }

        return right;
    }

	void do_test(_0201_bitwise_and_of_numbers_range* sol) {
        int ret;
        
        ret = sol->rangeBitwiseAnd(12, 15);
        cout << ret << endl;
        // Output : 12

        ret = sol->rangeBitwiseAnd(5, 7);
        cout << ret << endl;
        // Output : 4
        
        ret = sol->rangeBitwiseAnd(0, 0);
        cout << ret << endl;
        // Output : 0

        //Input : left = 1, right = 2147483647
        ret = sol->rangeBitwiseAnd(1, 2147483647);
        cout << ret << endl;
        // Output : 0
	}
};
