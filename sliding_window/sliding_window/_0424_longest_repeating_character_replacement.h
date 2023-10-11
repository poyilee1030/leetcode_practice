#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class _0424_longest_repeating_character_replacement
{
public:
	int characterReplacement(string s, int k) {
		vector<int> count(26);
		int longest = 0;
		int i = 0;
		for (int j = 0; j < s.size(); ++j)
		{
			count[s[j] - 'A']++;

			int max_f = 0;
			max_f = max(max_f, count[s[j] - 'A']);

			if ((j - i + 1 - max_f) <= k)
			{
				longest = j - i + 1;
			}
			else
			{
				count[s[i] - 'A']--;
				i++;
			}
		}
		return longest;
	}

	/*
	int characterReplacement(string s, int k) {
        unordered_map<char, int> charsmap;
		int longest = 0;
		int i = 0;
		for (int j = 0; j < s.size(); ++j)
		{
			int count = charsmap[s[j]];
			charsmap[s[j]] = count + 1;

			int max_f = 0;
			unordered_map<char, int>::iterator it;
			for (it = charsmap.begin(); it != charsmap.end(); it++)
			{
				if (it->second > max_f)
				{
					max_f = it->second;
				}
			}
			if ((j - i + 1 - max_f) <= k)
			{
				longest = j - i + 1;
			}
			else
			{
				charsmap[s[i]] = charsmap[s[i]] - 1;
				i++;
			}
		}
		return longest;
    }
	*/

	void do_test(_0424_longest_repeating_character_replacement* sol)
	{
		string s1 = "ABAB";
		int k1 = 2;
		int ret1 = sol->characterReplacement(s1, k1);
		cout << ret1 << endl;
		//Output : 4
		//Explanation : Replace the two 'A's with two 'B's or vice versa.
		

		string s2 = "AABABBA";
		int k2 = 1;
		int ret2 = sol->characterReplacement(s2, k2);
		cout << ret2 << endl;
		//Output : 4
		//Explanation : Replace the one 'A' in the middle with 'B' and form "AABBBBA".
		//The substring "BBBB" has the longest repeating letters, which is 4.
		//There may exists other ways to achive this answer too.
	}
};

