#pragma once

#include <string>
#include <iostream>

using namespace std;

class _0127_valid_palindrome
{
public:
    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.size() - 1;

        while (i < j)
        {
            while (!isalnum(s[i]) && i < j)
            {
                i++;
            }
            while (!isalnum(s[j]) && i < j)
            {
                j--;
            }
            if (tolower(s[i]) != tolower(s[j]))
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    void do_test(_0127_valid_palindrome *sol)
    {
        string s1 = "A man, a plan, a canal: Panama";
        bool ret1 = sol->isPalindrome(s1);
        cout << ret1 << endl;
        //Output : true
        //Explanation : "amanaplanacanalpanama" is a palindrome.
        
        string s2 = "race a car";
        bool ret2 = sol->isPalindrome(s2);
        cout << ret2 << endl;
        //Output : false
        //Explanation : "raceacar" is not a palindrome.        

        string s3 = " ";
        bool ret3 = sol->isPalindrome(s3);
        cout << ret3 << endl;
        //Output : true
    }
};


