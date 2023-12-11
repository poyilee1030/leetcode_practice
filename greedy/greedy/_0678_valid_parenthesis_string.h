#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class _0678_valid_parenthesis_string
{
public:
	bool checkValidString(string s) {
		int left_min = 0;
		int left_max = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				left_min++;
				left_max++;
			}
			else if (s[i] == ')') {
				left_min--;
				left_max--;
			}
			else {
				left_min--;
				left_max++;
			}
			if (left_max < 0) {
				return false;
			}
			if (left_min < 0) {
				left_min = 0;
			}
		}
		return (left_min == 0);
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
