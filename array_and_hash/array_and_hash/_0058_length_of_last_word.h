#pragma once

#include <iostream>
#include <string>

using namespace std;


class _0058_length_of_last_word
{
public:
    int lengthOfLastWord(string s) {
        int n = s.length();

        int ptr = n - 1;
        while (ptr >= 0 && s[ptr] == ' ') 
            ptr--; /* Skip the trailing whitespaces */

        int len = 0;
        while (ptr >= 0 && s[ptr--] != ' ') 
            len++; /* Counting the letters in the last word */

        return len;
    }

    /*
    int lengthOfLastWord(string s) {
        int left = 0;
        int right = s.size();
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
                if (right - i > 1)
                    break;
                else
                    right = i;
            else
                left = i;
        }
        return right - left;
    }
    */

	void do_test(_0058_length_of_last_word* sol) {
        string s1 = "Hello World";
        int ret1 = sol->lengthOfLastWord(s1);
        cout << ret1 << endl;
        // Output : 5
        // Explanation : The last word is "World" with length 5.
        
        string s2 = "   fly me   to   the moon  ";
        int ret2 = sol->lengthOfLastWord(s2);
        cout << ret2 << endl;
        // Output : 4
        // Explanation : The last word is "moon" with length 4.

        string s3 = "luffy is still joyboy";
        int ret3 = sol->lengthOfLastWord(s3);
        cout << ret3 << endl;
        // Output : 6
        // Explanation : The last word is "joyboy" with length 6.

        string s4 = " a";
        int ret4 = sol->lengthOfLastWord(s4);
        cout << ret4 << endl;
        // Output : 1
	}
};
