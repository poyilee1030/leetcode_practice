#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "../utils.h"

using namespace std;


class _0140_word_break_ii
{
public:
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        vector<string> curr;
        dfs(s, wordDict, curr, 0, ans);
        return ans;
    }

    void dfs(string s, vector<string>& wordDict, vector<string>& curr, int s_start, vector<string>& ans) {
        if (s_start == s.size()) {
            string tmp;
            for (string& x : curr) {
                tmp += x;
                tmp += " ";
            }
            if (!tmp.empty()) {
                tmp.pop_back();
                ans.push_back(tmp);
            }
        }
        for (int i = 0; i < wordDict.size(); i++) {
            string word = wordDict[i];
            int len = word.size();
            if (s.substr(s_start, len) == word) {
                curr.push_back(word);
                dfs(s, wordDict, curr, s_start + len, ans);
                curr.pop_back();
            }
        }
    }

	void do_test(_0140_word_break_ii* sol) {
        vector<string> wordDict;
        vector<string> res;

        wordDict = { "cat","cats","and","sand","dog" };
        res = sol->wordBreak("catsanddog", wordDict);
        print_vector(res);
        // Output: ["cats and dog","cat sand dog"]

        wordDict = { "apple","pen","applepen","pine","pineapple" };
        res = sol->wordBreak("pineapplepenapple", wordDict);
        print_vector(res);
        // Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]

        wordDict = { "cats","dog","sand","and","cat" };
        res = sol->wordBreak("catsandog", wordDict);
        print_vector(res);
        // Output: []
	}
};
