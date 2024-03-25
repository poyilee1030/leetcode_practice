#pragma once

#include <vector>
#include <string>
#include "utils.h"

using namespace std;


class _3076_shortest_uncommon_substring_in_an_array
{
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        const int n = arr.size();
        vector<string> answer(n);
        for (int i = 0; i < n; ++i) {
            for (int len = 1; answer[i].empty() && len <= arr[i].length(); ++len) {
                for (int b = 0; b + len <= arr[i].length(); ++b) {
                    const string s = arr[i].substr(b, len);
                    bool found = false;
                    for (int j = 0; !found && j < n; ++j) {
                        found = (j != i) && (arr[j].find(s) != string::npos);
                    }
                    if (!found && (answer[i].empty() || answer[i] > s)) {
                        answer[i] = s;
                    }
                }
            }
        }
        return answer;
    }

	void do_test(_3076_shortest_uncommon_substring_in_an_array* sol) {
        vector<string> arr1 = { "cab", "ad", "bad", "c" };
        vector<string> ret1 = sol->shortestSubstrings(arr1);
        print_vector(ret1);
        // Output : ["ab","","ba",""]

        vector<string> arr2 = { "abc", "bcd", "abcd" };
        vector<string> ret2 = sol->shortestSubstrings(arr2);
        print_vector(ret2);
        // Output : ["","","abcd"]
	}
};
