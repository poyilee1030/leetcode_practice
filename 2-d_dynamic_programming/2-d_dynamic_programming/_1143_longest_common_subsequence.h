#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class _1143_longest_common_subsequence
{
public:
	int longestCommonSubsequence(string text1, string text2) {
		return 0;
	}

	void do_test(_1143_longest_common_subsequence* sol) {
		string text11 = "abcde";
		string text12 = "ace";
		int ret1 = sol->longestCommonSubsequence(text11, text12);
		cout << ret1 << endl;
		// Output : 3
		// Explanation : The longest common subsequence is "ace" and its length is 3.
		

		string text21 = "abc";
		string text22 = "abc";
		int ret2 = sol->longestCommonSubsequence(text21, text22);
		cout << ret2 << endl;
		// Output : 3
		// Explanation : The longest common subsequence is "abc" and its length is 3.
		

		string text31 = "abc";
		string text32 = "def";
		int ret3 = sol->longestCommonSubsequence(text31, text32);
		cout << ret3 << endl;
		// Output : 0
		// Explanation : There is no such common subsequence, so the result is 0.
	}
};

