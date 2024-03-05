#pragma once

#include <iostream>
#include <string>

using namespace std;


class _1750_minimum_length_of_string_after_deleting_similar_ends
{
public:
    int minimumLength(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                break;
            }
            // 先移動右邊
            while (s[l] == s[r] && l < r) {
                r--;
            }
            // 使得接下來的 s[l] == s[r] 可以繼續成立
            r++;

            // 調整左邊
            while (s[l] == s[r] && l < r) {
                l++;
            }
            
            //把剛才做的 r++ 減回來
            r--;
        }
        return max(0, r - l + 1);
    }
    
    /*
    int minimumLength(string s) {
        int n = s.size();
        return helper(s, 0, n - 1);
    }
    
    int helper(string& s, int l, int r) {
        int n = r - l + 1;
        if (n <= 1) {
            return n;
        }

        if (s[l] != s[r]) {
            return n;
        }
        else {
            // s[l] == s[r]
            while (l < r && s[l] == s[l + 1])
                l++;
            while (l < r && s[r] == s[r - 1])
                r--;

            if (l + 1 >= r) {
                return 0;
            }
            else {
                return helper(s, l + 1, r - 1);
            }
        }
    }
    */

	void do_test(_1750_minimum_length_of_string_after_deleting_similar_ends* sol) {
        int ret = sol->minimumLength("ca");
        cout << ret << endl;
        // Output : 2
        // Explanation : You can't remove any characters, so the string stays as is.
        
        ret = sol->minimumLength("cabaabac");
        cout << ret << endl;
        /*
        Output : 0
        Explanation : An optimal sequence of operations is :
        -Take prefix = "c" and suffix = "c" and remove them, s = "abaaba".
        - Take prefix = "a" and suffix = "a" and remove them, s = "baab".
        - Take prefix = "b" and suffix = "b" and remove them, s = "aa".
        - Take prefix = "a" and suffix = "a" and remove them, s = "".
        */
        
        ret = sol->minimumLength("aabccabba");
        cout << ret << endl;
        // Output : 3

        ret = sol->minimumLength("bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb");
        cout << ret << endl;
        // Output: 1
	}
};
