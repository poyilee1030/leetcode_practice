#pragma once

#include <iostream>
#include <string>

using namespace std;


class _0005_longest_palindromic_substring
{
public:
	string longestPalindrome(string s) {
        int maxStart = 0;
        int maxLength = 1;

        for (int i = 0; i < s.size() - 1; i++) {
            middleOut(s, i, i, maxStart, maxLength);
            middleOut(s, i, i + 1, maxStart, maxLength);
        }

        return s.substr(maxStart, maxLength);
    }

    void middleOut(string s, int i, int j, int& maxStart, int& maxLength) {
        while (i >= 0 && j <= s.size() - 1 && s[i] == s[j]) {
            i--;
            j++;
        }
        if (j - i - 1 > maxLength) {
            maxStart = i + 1;
            maxLength = j - i - 1;
        }
    }

	void do_test(_0005_longest_palindromic_substring* sol)
	{
		string s1 = "babad";
		string ret1 = sol->longestPalindrome(s1);
		cout << ret1 << endl;
		/*
		Output : "bab"
		Explanation : "aba" is also a valid answer.
		*/
		
		string s2 = "cbbd";
		string ret2 = sol->longestPalindrome(s2);
		cout << ret2 << endl;
		//Output : "bb"
	}
};

