#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	Evaluate RPN, valid operators: +, -, *, /

	Stack, if num push, if operator apply to top 2 nums

	Time: O(n)
	Space: O(n)
*/

class _0150_evaluate_reverse_polish_notation
{
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> stk;

		for (int i = 0; i < tokens.size(); i++) {
			string token = tokens[i];

			if (token.size() > 1 || isdigit(token[0])) {
				stk.push(stoi(token));
				continue;
			}

			int num2 = stk.top();
			stk.pop();
			int num1 = stk.top();
			stk.pop();

			int result = 0;
			if (token == "+") {
				result = num1 + num2;
			}
			else if (token == "-") {
				result = num1 - num2;
			}
			else if (token == "*") {
				result = num1 * num2;
			}
			else {
				result = num1 / num2;
			}
			stk.push(result);
		}

		return stk.top();
	}

	void do_test(_0150_evaluate_reverse_polish_notation* sol)
	{
		vector<string> tokens1 = { "2", "1", "+", "3", "*" };
		int res1 = sol->evalRPN(tokens1);
		cout << res1 << endl;
		//Output : 9
		//Explanation : ((2 + 1) * 3) = 9

		vector<string> tokens2 = { "4", "13", "5", "/", "+" };
		int res2 = sol->evalRPN(tokens2);
		cout << res2 << endl;
		//Output : 6
		//Explanation : (4 + (13 / 5)) = 6

		vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
		int res3 = sol->evalRPN(tokens3);
		cout << res3 << endl;
		/*
		Output : 22
		Explanation : ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
		= ((10 * (6 / (12 * -11))) + 17) + 5
		= ((10 * (6 / -132)) + 17) + 5
		= ((10 * 0) + 17) + 5
		= (0 + 17) + 5
		= 17 + 5
		= 22
		*/
	}
};

