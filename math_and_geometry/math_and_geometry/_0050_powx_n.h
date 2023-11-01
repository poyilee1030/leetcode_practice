#pragma once

#include <iostream>

using namespace std;


class _0050_powx_n
{
public:
	double myPow(double x, int n) {
		return 0;
	}

	void do_test(_0050_powx_n* sol) {
		double x1 = 2.00000;
		int n1 = 10;
		double ret1 = sol->myPow(x1, n1);
		cout << ret1 << endl;
		// Output : 1024.00000
		

		double x2 = 2.10000;
		int n2 = 3;
		double ret2 = sol->myPow(x2, n2);
		cout << ret2 << endl;
		// Output : 9.26100
		

		double x3 = 2.00000;
		int n3 = -2;
		double ret3 = sol->myPow(x3, n3);
		cout << ret3 << endl;
		// Output : 0.25000
		// Explanation : 2 - 2 = 1 / 22 = 1 / 4 = 0.25
	}
};
