#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class _1930_unique_length_3_palindromic_subsequences
{
public:
	int countPalindromicSubsequence(string s) {
		unordered_set<char> letters;
		for (char c : s) {
			letters.insert(c);
		}

		int ans = 0;
		for (char letter : letters) {
			int i = -1;
			int j = 0;

			for (int k = 0; k < s.size(); k++) {
				if (s[k] == letter) {
					if (i == -1) {
						i = k;
					}

					j = k;
				}
			}

			unordered_set<char> between;
			for (int k = i + 1; k < j; k++) {
				between.insert(s[k]);
			}

			ans += between.size();
		}

		return ans;
	}

	void do_test(_1930_unique_length_3_palindromic_subsequences* sol) {
		string s1 = "aabca";
		int ret1 = sol->countPalindromicSubsequence(s1);
		cout << ret1 << endl;
		/*
		Output : 3
		Explanation : The 3 palindromic subsequences of length 3 are :
		- "aba" (subsequence of "aabca")
		- "aaa" (subsequence of "aabca")
		- "aca" (subsequence of "aabca")
		*/
		
		
		string s2 = "adc";
		int ret2 = sol->countPalindromicSubsequence(s2);
		cout << ret2 << endl;
		// Output : 0
		// Explanation : There are no palindromic subsequences of length 3 in "adc".
		

		string s3 = "bbcbaba";
		int ret3 = sol->countPalindromicSubsequence(s3);
		cout << ret3 << endl;
		/*
		Output : 4
		Explanation : The 4 palindromic subsequences of length 3 are :
		- "bbb" (subsequence of "bbcbaba")
		- "bcb" (subsequence of "bbcbaba")
		- "bab" (subsequence of "bbcbaba")
		- "aba" (subsequence of "bbcbaba")
		*/
	}
};
