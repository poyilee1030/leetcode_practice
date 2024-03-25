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
        int ret;

        ret = sol->lengthOfLastWord("Hello World");
        cout << ret << endl;
        // Output : 5
        // Explanation : The last word is "World" with length 5.
        
        ret = sol->lengthOfLastWord("   fly me   to   the moon  ");
        cout << ret << endl;
        // Output : 4
        // Explanation : The last word is "moon" with length 4.

        ret = sol->lengthOfLastWord("luffy is still joyboy");
        cout << ret << endl;
        // Output : 6
        // Explanation : The last word is "joyboy" with length 6.

        ret = sol->lengthOfLastWord(" a");
        cout << ret << endl;
        // Output : 1
	}
};
