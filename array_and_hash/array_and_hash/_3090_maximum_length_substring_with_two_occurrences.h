#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;


class _3090_maximum_length_substring_with_two_occurrences {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> freq;
        int l = 0;
        int r = 0;
        int ans = 0;
        while (r < s.size()) {
            freq[s[r]]++;
            while (freq[s[r]] > 2) {
                freq[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }

	void do_test(_3090_maximum_length_substring_with_two_occurrences* sol) {
        int ret = 0;
        ret = sol->maximumLengthSubstring("bcbbbcba");
        cout << ret << endl;
        // 4

        ret = sol->maximumLengthSubstring("aaaa");
        cout << ret << endl;
        // 2

        ret = sol->maximumLengthSubstring("acbabccbc");
        cout << ret << endl;
        // 6

        ret = sol->maximumLengthSubstring("adaddccdb");
        cout << ret << endl;
        // 5

        ret = sol->maximumLengthSubstring("dc");
        cout << ret << endl;
        // 2
	}
};
