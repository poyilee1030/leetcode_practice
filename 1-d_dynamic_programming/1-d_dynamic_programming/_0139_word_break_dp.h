#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/*
	Given a string & dictionary, return true if:
	Can segment string into 1 or more dictionary words

	DP, at each loop, substring, check if in dict, & store

	Time: O(n^3)
	Space: O(n)
*/


class _0139_word_break_dp
{
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int n = s.size();
		vector<bool>dp(n + 1, 0);

		dp[0] = true;

		for (int i = 1; i <= n; i++)
		{
			// updaet dp[i]
			for (auto x : wordDict)
			{
				if (i >= x.size() && s.substr(i - x.size(), x.size()) == x && dp[i - x.size()])
				{
					dp[i] = true;
					break;
				}
			}
		}

		return dp[n];
	}

	void do_test(_0139_word_break_dp* sol)
	{
		string s1 = "leetcode";
		vector<string> wordDict1 = { "leet", "code" };
		bool ret1 = sol->wordBreak(s1, wordDict1);
		cout << ret1 << endl;
		//Output : true
		//Explanation : Return true because "leetcode" can be segmented as "leet code".
		

		string s2 = "applepenapple";
		vector<string> wordDict2 = { "apple", "pen" };
		bool ret2 = sol->wordBreak(s2, wordDict2);
		cout << ret2 << endl;
		//Output : true
		//Explanation : Return true because "applepenapple" can be segmented as "apple pen apple".
		//Note that you are allowed to reuse a dictionary word.
		

		string s3 = "catsandog";
		vector<string> wordDict3 = { "cats", "dog", "sand", "and", "cat" };
		bool ret3 = sol->wordBreak(s3, wordDict3);
		cout << ret3 << endl;
		//Output : false
	}
};
