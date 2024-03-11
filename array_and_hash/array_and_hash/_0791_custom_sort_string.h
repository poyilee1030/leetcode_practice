#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class _0791_custom_sort_string {
    int orderIdx[26];
public:
    
    string customSortString(string order, string s) {
        string ans;
        vector<int> count(26, 0);
        for (auto ch : s) {
            count[ch - 'a']++;
        }
        for (int i = 0; i < order.size(); i++) {
            while (count[order[i] - 'a'] > 0) {
                ans += order[i];
                count[order[i] - 'a']--;
            }
        }
        for (int i = 0; i < 26; i++) {
            while (count[i] > 0) {
                ans += i + 'a';
                count[i]--;
            }
        }
        return ans;
    }
    
    /*
    string customSortString(string order, string s) {

        for (int i = 0; i < 26; i++)
            orderIdx[i] = 0;

        for (int i = 0; i < order.size(); i++) {
            orderIdx[order[i] - 'a'] = i;
        }

        sort(s.begin(), s.end(), [this](const char& a, const char& b) {
            return orderIdx[a - 'a'] < orderIdx[b - 'a'];
            });

        return s;
    }
    */

	void do_test(_0791_custom_sort_string* sol) {
        string ret1 = sol->customSortString("cba", "abcd");
        cout << ret1 << endl;
        /*
        Output : "cbad"
        Explanation :
            "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".
            Since "d" does not appear in order, it can be at any position in the returned string.
            "dcba", "cdba", "cbda" are also valid outputs.
        */
        

        string ret2 = sol->customSortString("bcafg", "abcd");
        cout << ret2 << endl;

        // Output : "bcad"
	}
};



