#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


class _0567_permutation_in_string
{
public:
	// better solution
	bool checkInclusion(string s1, string s2) {
		int m = s1.size();
		int n = s2.size();
		if (m > n)
			return false;

		vector<int> count(26);
		for (int i = 0; i < m; i++) {
			count[s1[i] - 'a']++;
			count[s2[i] - 'a']--;
		}
		if (isPermutation(count)) {
			return true;
		}

		for (int i = m; i < n; i++) {
			count[s2[i] - 'a']--;
			count[s2[i - m] - 'a']++;
			if (isPermutation(count)) {
				return true;
			}
		}

		return false;
	}
	
	bool isPermutation(vector<int>& count) {
		for (int i = 0; i < 26; i++) {
			if (count[i] != 0) {
				return false;
			}
		}
		return true;
	}
	/* 用了兩個 vector 來統計比較，其實可以優化成同一個 vector
	bool checkInclusion(string s1, string s2) {
		if (s1.size() > s2.size())
			return false;

		vector<int> count1(26);
		vector<int> count2(26);
		for (int i = 0; i < s1.size(); i++)
		{
			count1[s1[i] - 'a'] += 1;
			count2[s2[i] - 'a'] += 1;
		}

		int match = 0;
		for (int k = 0; k < 26; k++)
		{
			if (count1[k] == count2[k])
				match += 1;
		}
		if (match == 26)
			return true;
		
		for (int r = s1.size(); r < s2.size(); r++)
		{
			int l = r - s1.size();
			count2[s2[l] - 'a'] -= 1;
			count2[s2[r] - 'a'] += 1;

			match = 0;
			for (int k = 0; k < 26; k++)
			{
				if (count1[k] == count2[k])
					match += 1;
			}
			if (match == 26)
				return true;
		}
		return false;
	}
	*/

	void do_test(_0567_permutation_in_string* sol)
	{
		bool ret;

		ret = sol->checkInclusion("ab", "eidbaooo");
		cout << ret << endl;
		//Output : true
		//Explanation : s2 contains one permutation of s1("ba").
		
		ret = sol->checkInclusion("ab", "eidboaoo");
		cout << ret << endl;
		//Output : false

		ret = sol->checkInclusion("adc", "dcda");
		cout << ret << endl;
		//Output : true
	}
};
