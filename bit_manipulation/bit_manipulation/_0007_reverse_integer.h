#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0007_reverse_integer
{
public:
	int reverse(int x) {
		return 0;
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
