#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class _0043_multiply_strings
{
public:
	string multiply(string num1, string num2) {
		string s;
		return s;
	}

	void do_test(_0043_multiply_strings* sol) {
		string num11 = "2";
		string num12 = "3";
		string ret1 = sol->multiply(num11, num12);
		cout << ret1 << endl;
		// Output : "6"
		

		string num21 = "123";
		string num22 = "456";
		string ret2 = sol->multiply(num21, num22);
		cout << ret2 << endl;
		// Output : "56088"
	}
};
