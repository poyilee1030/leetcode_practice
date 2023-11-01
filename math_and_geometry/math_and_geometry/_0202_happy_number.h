#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0202_happy_number
{
public:
	bool isHappy(int n) {
		return false;
	}

	void do_test(_0202_happy_number* sol) {
		int n1 = 19;
		bool ret1 = sol->isHappy(n1);
		cout << ret1 << endl;
		/*
		Output : true
		Explanation :
		12 + 92 = 82
		82 + 22 = 68
		62 + 82 = 100
		12 + 02 + 02 = 1
		*/

		int n2 = 2;
		bool ret2 = sol->isHappy(n2);
		cout << ret2 << endl;
		// Output : false
	}
};
