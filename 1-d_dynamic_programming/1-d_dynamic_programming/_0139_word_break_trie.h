#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/*
	Given a string & dictionary, return true if:
	Can segment string into 1 or more dictionary words

	DP, at each loop, substring, check if in dict, & store

	Time: O(n^3)
	Space: O(n)
*/


class _0139_word_break_trie
{
    class TrieNode
    {
    public:
        TrieNode* next[26];
        bool end;
        TrieNode()
        {
            end = false;
            for (int i = 0;i < 26;i++)
                next[i] = NULL;
        }
    };
    TrieNode* root;
    int memo[300];
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        root = new TrieNode();
        for (auto word : wordDict)
        {
            TrieNode* node = root;
            for (auto ch : word)
            {
                if (node->next[ch - 'a'] == NULL)
                    node->next[ch - 'a'] = new TrieNode();
                node = node->next[ch - 'a'];
            }
            node->end = true;
        }

        return dfs(s, 0);
    }

    bool dfs(string& s, int cur)
    {
        if (memo[cur] == 1) return false;

        if (cur == s.size())
            return true;

        TrieNode* node = root;
        for (int i = cur; i < s.size(); i++)
        {
            if (node->next[s[i] - 'a'] != NULL)
            {
                node = node->next[s[i] - 'a'];
                if (node->end == true && dfs(s, i + 1))
                    return true;
            }
            else
            {
                break;
            }
        }

        memo[cur] = 1;
        return false;
	}

	void do_test(_0139_word_break_trie* sol)
	{
		string s1 = "leetcode";
		vector<string> wordDict1 = { "leet", "code" };
		bool ret1 = sol->wordBreak(s1, wordDict1);
		cout << ret1 << endl;
		//Output : true
		//Explanation : Return true because "leetcode" can be segmented as "leet code".
		

		string s2 = "applepenapple";
		vector<string> wordDict2 = { "apple", "pen" };
		bool ret2 = sol->wordBreak(s2, wordDict2);
		cout << ret2 << endl;
		//Output : true
		//Explanation : Return true because "applepenapple" can be segmented as "apple pen apple".
		//Note that you are allowed to reuse a dictionary word.
		

		string s3 = "catsandog";
		vector<string> wordDict3 = { "cats", "dog", "sand", "and", "cat" };
		bool ret3 = sol->wordBreak(s3, wordDict3);
		cout << ret3 << endl;
		//Output : false
	}
};
