#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


class _0076_minimum_window_substring
{
public:

	string minWindow(string s, string t) {
		if (t.size() > s.size())
			return "";

		unordered_map<char, int> uomap;
		for (int i = 0; i < t.size(); ++i)
		{
			uomap[t[i]] -= 1;
		}

		int counter = 0 - t.size();
		int minStart = 0;
		int minLength = INT_MAX;
		
		int l = 0;
		int r = 0;
		while (r < s.size())
		{
			if (uomap[s[r]] < 0)
				counter++;

			uomap[s[r]]++;
			r++;

			while (counter == 0)
			{
				if (r - l < minLength)
				{
					minStart = l;
					minLength = r - l;
				}

				uomap[s[l]]--;
				if (uomap[s[l]] < 0)
					counter--;

				l++;
			}
		}

		if (minLength != INT_MAX)
			return s.substr(minStart, minLength);

		return "";
	}

	void do_test(_0076_minimum_window_substring* sol)
	{
		string s1 = "ADOBECODEBANC";
		string t1 = "ABC";
		string ret1 = sol->minWindow(s1, t1);
		cout << ret1 << endl;
		//Output : "BANC"
		//Explanation : The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
		

		string s2 = "a";
		string t2 = "a";
		string ret2 = sol->minWindow(s2, t2);
		cout << ret2 << endl;
		//Output : "a"
		//Explanation : The entire string s is the minimum window.
		

		string s3 = "a";
		string t3 = "aa";
		string ret3 = sol->minWindow(s3, t3);
		cout << ret3 << endl;
		//Output : ""
		//Explanation : Both 'a's from t must be included in the window.
		//Since the largest window of s only has one 'a', return empty string.
	}
};

