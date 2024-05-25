#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class _0139_word_break
{
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> memo(n, false);
        return dfs(s, wordDict, 0, memo);
    }

    bool dfs(string& s, vector<string>& wordDict, int s_start, vector<bool>& memo) {
        if (s_start == s.size())
            return true;

        //�H�e���Ѫ�case, ��ܱq s_start �}�l�O�L�k�������Ϊ��A���� return false
        if (memo[s_start])
            return false;

        for (int i = 0; i < wordDict.size(); i++) {
            string word = wordDict[i];
            int len = word.size();
            if (s.substr(s_start, len) == word) {
                bool ret = dfs(s, wordDict, s_start + len, memo);
                if (ret)
                    return true;
            }
        }

        //�O���Ѫ�case, ��ܱq s_start �}�l�O�L�k�������Ϊ�
        memo[s_start] = true;
        return false;
    }

	void do_test(_0139_word_break* sol) {
        vector<string> wordDict;
        bool res;

        wordDict = { "leet", "code" };
        res = sol->wordBreak("leetcode", wordDict);
        cout << res << endl;
        // Output: true

        wordDict = { "apple", "pen" };
        res = sol->wordBreak("applepenapple", wordDict);
        cout << res << endl;
        // Output: true

        wordDict = { "cats", "dog", "sand", "and", "cat" };
        res = sol->wordBreak("catsandog", wordDict);
        cout << res << endl;
        // Output: false

        wordDict = { "aaaa","aaa" };
        res = sol->wordBreak("aaaaaaa", wordDict);
        cout << res << endl;
        // Output: true

        wordDict = { "car","ca","rs" };
        res = sol->wordBreak("cars", wordDict);
        cout << res << endl;
        // Output: true
	}
};