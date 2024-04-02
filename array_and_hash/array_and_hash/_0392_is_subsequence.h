#pragma once

#include <iostream>
#include <string>

using namespace std;


class _0392_is_subsequence
{
public:
	bool isSubsequence(string s, string t) {
		int start = 0;
		string tmp = t;
		for (auto c : s) {
			tmp = tmp.substr(start, tmp.size());
			if (tmp.size() == 0)
				return false;
			start = tmp.find(c) + 1;
			if (start <= 0)
				return false;
		}
		return true;
	}

	void do_test(_0392_is_subsequence* sol) {
		bool ret;
		
		ret = sol->isSubsequence("aaaaaa", "bbaaaa");
		cout << ret << endl;
		// Output : false

		ret = sol->isSubsequence("abc", "ahbgdc");
		cout << ret << endl;
		// Output : true
		
		ret = sol->isSubsequence("axc", "ahbgdc");
		cout << ret << endl;
		// Output : false
	}
};
