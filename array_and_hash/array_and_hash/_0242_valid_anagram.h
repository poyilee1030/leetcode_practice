#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

/*
anagram 易位構詞
易位構詞是一類文字遊戲，是將組成一個詞或短句的字母重新排列順序，
原文中所有字母的每次出現都被使用一次，這樣構造出另外一些新的詞或短句。
*/

class _0242_valid_anagram
{
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) 
            return false;

        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;

        for (unsigned int i = 0; i < s.size(); i++) {
            smap[s[i]]++;
            tmap[t[i]]++;
        }

        for (unsigned int i = 0; i < smap.size(); i++) {
            if (smap[i] != tmap[i]) 
                return false;
        }
        return true;
    }

    void do_test(_0242_valid_anagram *sol) {
        bool ret;

        ret = sol->isAnagram("anagram", "nagaram");
        cout << ret << endl;

        ret = sol->isAnagram("rat", "car");
        cout << ret << endl;
    }
};
