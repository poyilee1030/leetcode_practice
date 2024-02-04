#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


class _0076_minimum_window_substring
{
public:
	// �ۤv�Q���A���M�L�F���Ĳv�ܮt
	// ���ӬO��� map �Ӫ�ɶ�
	string minWindow(string s, string t) {
		if (t.size() > s.size())
			return "";
		unordered_map<char, int> target_map;
		for (char c : t)
			target_map[c]++;

		unordered_map<char, int> current_map;

		int l = 0;
		int r = 0;
		int min_start = -1;
		int min_length = INT_MAX;

		while (r <= s.size() || l < r) {
			if (currMapIsValid(target_map, current_map)) {
				if (r - l < min_length) {
					min_length = r - l;
					min_start = l;
				}

				char c = s[l];
				current_map[c]--;
				l++;
			}
			else {
				if (r == s.size())
					break;
				char c = s[r];
				current_map[c]++;
				r++;
			}
		}
		if (min_start < 0) {
			return "";
		}
		return s.substr(min_start, min_length);
	}

	bool currMapIsValid(unordered_map<char, int>& target_map, unordered_map<char, int>& current_map) {
		for (auto it : target_map) {
			if (current_map.find(it.first) == current_map.end())
				return false;
			if (it.second > current_map[it.first])
				return false;
		}
		return true;
	}
	/*
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
	*/
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

