#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0371_sum_of_two_integers
{
public:
	int getSum(int a, int b) {

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
