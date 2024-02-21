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
        
        int ret0 = sol->rangeBitwiseAnd(12, 15);
        cout << ret0 << endl;
        // Output : 12

        int ret1 = sol->rangeBitwiseAnd(5, 7);
        cout << ret1 << endl;
        // Output : 4
        
        int ret2 = sol->rangeBitwiseAnd(0, 0);
        cout << ret2 << endl;
        // Output : 0

        //Input : left = 1, right = 2147483647
        int ret3 = sol->rangeBitwiseAnd(1, 2147483647);
        cout << ret3 << endl;
        // Output : 0
	}
};
