#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
	Given a signed 32-bit integer, return it with its digits reversed
	Ex. x = 123 -> 321, x = -123 -> -321, x = 120 -> 21

	Reverse bit-by-bit starting from right, shift right off every time

	Time: O(log x)
	Space: O(1)
*/

class _0007_reverse_integer
{
public:
	int reverse(int x) {
		// note:
		// if int oo = -12;
		// then oo % 10 = -2
		int rev = 0;
		while (x != 0) {
			int temp = x % 10;
			x /= 10;
			if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && temp > 7)) {
				return 0;
			}
			if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && temp < -8)) {
				return 0;
			}
			rev = rev * 10 + temp;
		}
		return rev;
	}

	void do_test(_0007_reverse_integer* sol) {
		int x1 = 123;
		int ret1 = sol->reverse(x1);
		cout << ret1 << endl;
		// Output : 321
		
		int x2 = -123;
		int ret2 = sol->reverse(x2);
		cout << ret2 << endl;
		// Output : -321
		
		int x3 = 120;
		int ret3 = sol->reverse(x3);
		cout << ret3 << endl;
		// Output : 21
	}
};
