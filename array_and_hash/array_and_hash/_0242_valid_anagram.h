#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

/*
anagram ����c��
����c���O�@����r�C���A�O�N�զ��@�ӵ��εu�y���r�����s�ƦC���ǡA
��夤�Ҧ��r�����C���X�{���Q�ϥΤ@���A�o�˺c�y�X�t�~�@�Ƿs�����εu�y�C
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
        string s1 = "anagram";
        string t1 = "nagaram";
        bool ret1 = sol->isAnagram(s1, t1);
        cout << ret1 << endl;

        string s2 = "rat";
        string t2 = "car";
        bool ret2 = sol->isAnagram(s2, t2);
        cout << ret2 << endl;
    }
};
