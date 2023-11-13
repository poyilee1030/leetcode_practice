#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class _2785_sort_vowels_in_a_string
{
public:
	string sortVowels(string s) {
		
		vector<char> vowels;
		for (int i = 0; i < s.size(); i++) {
			char c = s[i];
			if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
				c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				vowels.push_back(c);
				s[i] = '#';
			}
		}

		if (vowels.empty()) {
			return s;
		}

		sort(vowels.begin(), vowels.end());
		// How to sort in descending order ? 
		// sort(v.begin(), v.end(), greater<int>());

		// Sorting the vector using user-defined lambda expression(return type bool)
		// sort(v.begin(), v.end(), [](int& a, int& b) { return a > b; });
		
		int vIndex = 0;
		for (int i = 0; i < s.size(); i++) {
			char c = s[i];
			if (c == '#') {
				s[i] = vowels[vIndex];
				vIndex++;
			}
		}
		return s;
	}

	void do_test(_2785_sort_vowels_in_a_string* sol) {
		string s1 = "lEetcOde";
		string ret1 = sol->sortVowels(s1);
		cout << ret1 << endl;
		/*
		Output : "lEOtcede"
		Explanation : 'E', 'O', and 'e' are the vowels in s; 'l', 't', 'c', and 'd' are all consonants.
		The vowels are sorted according to their ASCII values, and the consonants remain in the same places.
		*/
		
		string s2 = "lYmpH";
		string ret2 = sol->sortVowels(s2);
		cout << ret2 << endl;
		/*
		Output : "lYmpH"
		Explanation : There are no vowels in s(all characters in s are consonants), so we return "lYmpH".
		*/
	}
};
