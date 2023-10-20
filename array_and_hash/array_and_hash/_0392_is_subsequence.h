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
		for (auto c : s)
		{
			tmp = tmp.substr(start, tmp.size());
			if (tmp.size() == 0)
				return false;
			start = tmp.find(c) + 1;
			if (start <= 0)
				return false;
		}
		return true;
	}

	void do_test(_0392_is_subsequence* sol)
	{
		string s0 = "aaaaaa";
		string t0 = "bbaaaa";
		bool ret0 = sol->isSubsequence(s0, t0);
		cout << ret0 << endl;
		// Output : false

		string s1 = "abc";
		string t1 = "ahbgdc";
		bool ret1 = sol->isSubsequence(s1, t1);
		cout << ret1 << endl;
		// Output : true
		
		string s2 = "axc";
		string t2 = "ahbgdc";
		bool ret2 = sol->isSubsequence(s2, t2);
		cout << ret2 << endl;
		// Output : false
	}
};


