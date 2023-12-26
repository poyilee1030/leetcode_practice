#pragma once

#include <iostream>

using namespace std;


class _0050_powx_n
{
public:
	double myPow(double x, int n) {
		long exponent = abs(n);
		double res = helper(x, exponent);
		if (n >= 0) {
			return res;
		}
		else {
			return 1 / res;
		}
	}

	double helper(double x, long n) {
		if (x == 0) {
			return 0;
		}
		if (n == 0) {
			return 1;
		}

		double res = helper(x, int(n / 2));
		res = res * res;

		if (n % 2) {
			return x * res;
		}
		else {
			return res;
		}
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
