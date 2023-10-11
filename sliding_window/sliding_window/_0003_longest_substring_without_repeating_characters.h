#pragma once

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class _0003_longest_substring_without_repeating_characters
{
public:
	int lengthOfLongestSubstring(string s) {
		unordered_set<char> charset;
		int l = 0;
		int max_length = 0;
		for (int r = 0; r < s.size(); ++r)
		{
			while (charset.find(s[r]) != charset.end())
			{
				charset.erase(s[l]);
				++l;
			}
			charset.insert(s[r]);
			max_length = max(max_length, r - l + 1);
		}
		return max_length;
	}

	void do_test(_0003_longest_substring_without_repeating_characters *sol)
	{
		string s1 = "abcabcbb";
		int ret1 = sol->lengthOfLongestSubstring(s1);
		cout << ret1 << endl;
		//Output : 3
		//Explanation : The answer is "abc", with the length of 3.
		

		string s2 = "bbbbb";
		int ret2 = sol->lengthOfLongestSubstring(s2);
		cout << ret2 << endl;
		//Output : 1
		//Explanation : The answer is "b", with the length of 1.
		

		string s3 = "pwwkew";
		int ret3 = sol->lengthOfLongestSubstring(s3);
		cout << ret3 << endl;
		//Output : 3
		//Explanation : The answer is "wke", with the length of 3.
		//Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
	}
};

