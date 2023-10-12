#pragma once

#include <iostream>
#include <string>

using namespace std;


class _0647_palindromic_substrings
{
public:
	int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            middleOut(s, i, i, result);
            middleOut(s, i, i + 1, result);
        }
        return result;
    }

    void middleOut(string s, int i, int j, int& result) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            result++;
            i--;
            j++;
        }
    }

	void do_test(_0647_palindromic_substrings* sol)
	{
		string s1 = "abc";
		int ret1 = sol->countSubstrings(s1);
		cout << ret1 << endl;
		// Output : 3
		// Explanation : Three palindromic strings : "a", "b", "c".

		string s2 = "aaa";
		int ret2 = sol->countSubstrings(s2);
		cout << ret2 << endl;
		// Output : 6
		// Explanation : Six palindromic strings : "a", "a", "a", "aa", "aa", "aaa".
	}
};
