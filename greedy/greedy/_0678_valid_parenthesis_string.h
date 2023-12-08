#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class _0678_valid_parenthesis_string
{
public:
	bool checkValidString(string s) {
		return false;
	}

	void do_test(_0678_valid_parenthesis_string* sol) {
		string s1 = "()";
		bool ret1 = sol->checkValidString(s1);
		cout << ret1 << endl;
		// Output : true
		

		string s2 = "(*)";
		bool ret2 = sol->checkValidString(s2);
		cout << ret2 << endl;
		// Output : true
		

		string s3 = "(*))";
		bool ret3 = sol->checkValidString(s3);
		cout << ret3 << endl;
		// Output : true

		string s4 = "((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()";
		bool ret4 = sol->checkValidString(s4);
		cout << ret4 << endl;
		// Output : true

	}
};
