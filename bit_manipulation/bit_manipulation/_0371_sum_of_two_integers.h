#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
	Given 2 ints, return sum w/o using +/-
	Ex. a = 1 b = 2 -> 3, a = 2 b = 3 -> 5

	XOR for addition, AND for carry bit

	Time: O(n)
	Space: O(1)
*/

class _0371_sum_of_two_integers
{
public:
	int getSum(int a, int b) {
		while (b != 0) {
			int carry = a & b;
			a = a ^ b;
			b = (unsigned)carry << 1;
		}
		return a;
	}

	void do_test(_0371_sum_of_two_integers* sol) {
		int a1 = 1;
		int b1 = 2;
		int ret1 = sol->getSum(a1, b1);
		cout << ret1 << endl;
		// Output : 3
		
		int a2 = 2;
		int b2 = 3;
		int ret2 = sol->getSum(a2, b2);
		cout << ret2 << endl;
		// Output : 5
	}
};
