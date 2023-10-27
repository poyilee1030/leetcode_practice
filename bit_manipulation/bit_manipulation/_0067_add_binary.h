#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0067_add_binary
{
public:
	string addBinary(string a, string b) {
		return "";
	}

	void do_test(_0067_add_binary* sol) {
		string a1 = "11";
		string b1 = "1";
		string ret1 = sol->addBinary(a1, b1);
		cout << ret1 << endl;
		// Output : "100"
		

		string a2 = "1010";
		string b2 = "1011";
		string ret2 = sol->addBinary(a2, b2);
		cout << ret2 << endl;
		// Output : "10101"
	}
};
