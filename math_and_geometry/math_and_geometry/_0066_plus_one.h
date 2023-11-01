#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0066_plus_one
{
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;

        for (int i = digits.size() - 1; i >= 0; --i) {
            if (carry)
                digits[i] += 1;

            carry = digits[i] / 10;
            digits[i] = digits[i] % 10;
        }

        if (carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }

	void do_test(_0066_plus_one* sol) {
        vector<int> digits1 = { 1, 2, 3 };
        vector<int> ret1 = sol->plusOne(digits1);
        print_res(ret1);
        /*
        Output : [1, 2, 4]
        Explanation : The array represents the integer 123.
        Incrementing by one gives 123 + 1 = 124.
        Thus, the result should be[1, 2, 4].
        */

        vector<int> digits2 = { 4, 3, 2, 1 };
        vector<int> ret2 = sol->plusOne(digits2);
        print_res(ret2);
        /*
        Output : [4, 3, 2, 2]
        Explanation : The array represents the integer 4321.
        Incrementing by one gives 4321 + 1 = 4322.
        Thus, the result should be[4, 3, 2, 2].
        */

        vector<int> digits3 = { 9 };
        vector<int> ret3 = sol->plusOne(digits3);
        print_res(ret3);
        /*
        Output : [1, 0]
        Explanation : The array represents the integer 9.
        Incrementing by one gives 9 + 1 = 10.
        Thus, the result should be[1, 0].
        */
	}

    void print_res(vector<int> res) {
        cout << "[";
        for (int i = 0; i < res.size(); i++) {
            cout << res[i];
            if (i < res.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }
};
