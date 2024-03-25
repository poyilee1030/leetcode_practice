#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class _0014_longest_common_prefix
{
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = strs[0];
        int charIndex = 0;

        //finding minimum string length  - that could be max common prefix
        long maxCharIndex = strs[0].length();
        for (int i = 1; i < strs.size(); ++i) {
            if (strs[i].length() < maxCharIndex) {
                maxCharIndex = strs[i].length();
            }
        }

        while (charIndex < maxCharIndex) {
            char prevChar = strs[0][charIndex];
            for (int i = 1; i < strs.size(); ++i) {
                if (prevChar == strs[i][charIndex]) {
                    continue;
                }
                return result.substr(0, charIndex);
            }
            ++charIndex;
            result += prevChar;
        }
        return result.substr(0, charIndex);
    }
    /*
    string longestCommonPrefix(vector<string>& strs) {

        string prefix = "";
        int minlength = INT_MAX;
        for (int i = 0; i < strs.size(); i++) {
            string curs = strs[i];
            if (curs.size() < minlength)
                minlength = curs.size();
        }

        for (int idx = 0; idx < minlength; idx++) {
            if (!helper(strs, idx, prefix))
                break;
        }

        return prefix;
    }

    bool helper(vector<string>& strs, int idx, string& prefix) {
        char tmp;
        for (int i = 0; i < strs.size(); i++) {
            string curs = strs[i];
            if (i == 0)
                tmp = curs[idx];

            if (tmp != curs[idx])
                return false;

            if (i == strs.size() - 1)
                prefix += tmp;
        }
        return true;
    }
    */

	void do_test(_0014_longest_common_prefix* sol)
	{
        vector<string> strs;
        string ret;
        strs = { "flower", "flow", "flight" };
        ret = sol->longestCommonPrefix(strs);
        cout << ret << endl;
        // Output : "fl"
        
        strs = { "dog", "racecar", "car" };
        ret = sol->longestCommonPrefix(strs);
        cout << ret << endl;
        // Output : ""
        // Explanation : There is no common prefix among the input strings.
	}
};
