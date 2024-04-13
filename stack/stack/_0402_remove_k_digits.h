#pragma once

#include <iostream>
#include <string>

using namespace std;


class _0402_remove_k_digits
{
public:
	string removeKdigits(string num, int k) {
		stack<char> stk;
		for (int i = 0; i < num.size(); i++) {
			while (!stk.empty() && k > 0 && stk.top() > num[i]) {
				stk.pop();
				k--;
			}
			stk.push(num[i]);
		}

		// 已經走到最後，但 k 還大於 0，從最上面開始 pop
		while (!stk.empty() && k > 0) {
			stk.pop();
			k--;
		}

		string ans;
		while (!stk.empty()) {
			ans += stk.top();
			stk.pop();
		}

		while (ans.size() > 0 && ans.back() == '0') {
			ans.pop_back();
		}

		reverse(ans.begin(), ans.end());
		return (ans == "") ? "0" : ans;
	}

	void do_test(_0402_remove_k_digits* sol) {
		string ret;

		ret = sol->removeKdigits("1432219", 3);
		cout << ret << endl;
		// Output: 1219

		ret = sol->removeKdigits("10200", 1);
		cout << ret << endl;
		// Output: 200

		ret = sol->removeKdigits("10", 2);
		cout << ret << endl;
		// Output: 0
	}
};
