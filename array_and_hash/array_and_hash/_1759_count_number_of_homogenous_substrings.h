#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class _1759_count_number_of_homogenous_substrings
{
public:
    int countHomogenous(string s) {
        int ans = 0;
        int currStreak = 0;
        int MOD = 1e9 + 7;

        for (int i = 0; i < s.size(); i++) {
            if (i == 0 || s[i] == s[i - 1]) {
                currStreak++;
            }
            else {
                currStreak = 1;
            }

            ans = (ans + currStreak) % MOD;
        }

        return ans;
    }
    /*
    int countHomogenous(string s) {
        int result = 0;
        int MOD = 1e9 + 7;
        string last;
        last.push_back(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == last[0]) {
                last.push_back(s[i]);
            }
            else {
                for (int j = 1; j < last.size() + 1; j++) {
                    result = (result + j) % MOD;
                }
                last.clear();
                last.push_back(s[i]);
            }
        }
        for (int j = 1; j < last.size() + 1; j++) {
            result = (result + j) % MOD;
        }
        return result;
    }
    */
    

	void do_test(_1759_count_number_of_homogenous_substrings* sol) {
        string s1 = "abbcccaa";
        int ret1 = sol->countHomogenous(s1);
        cout << ret1 << endl;
        /*
        Output : 13
		Explanation : The homogenous substrings are listed as below :
		"a"   appears 3 times.
		"aa"  appears 1 time.
		"b"   appears 2 times.
		"bb"  appears 1 time.
		"c"   appears 3 times.
		"cc"  appears 2 times.
		"ccc" appears 1 time.
		3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.
        */

        string s2 = "xy";
        int ret2 = sol->countHomogenous(s2);
        cout << ret2 << endl;
        // Output : 2
        // Explanation : The homogenous substrings are "x" and "y".

        string s3 = "zzzzz";
        int ret3 = sol->countHomogenous(s3);
        cout << ret3 << endl;
	    //Output : 15
	}
};
