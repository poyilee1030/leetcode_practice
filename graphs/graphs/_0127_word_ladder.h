#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

/*
    Given 2 words & a dictionary, return min # of words to transform b/w them
    Ex. begin = "hit", end = "cog", dict = ["hot","dot","dog","lot","log","cog"] -> 5
    "hit" -> "hot" -> "dot" -> "dog" -> "cog"

    BFS, change 1 letter at a time (neighbors), if in dict add to queue, else skip

    Time: O(m^2 x n) -> m = length of each word, n = # of words in input word list
    Space: O(m^2 x n)
*/

class _0127_word_ladder
{
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for (int i = 0; i < wordList.size(); i++) {
            dict.insert(wordList[i]);
        }

        queue<string> q;
        q.push(beginWord);

        int result = 1;

        while (!q.empty()) {
            int count = q.size();

            for (int i = 0; i < count; i++) {
                string word = q.front();
                q.pop();

                if (word == endWord) {
                    return result;
                }
                dict.erase(word);

                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = k + 'a';
                        if (dict.find(word) != dict.end()) {
                            q.push(word);
                            dict.erase(word);
                        }
                        word[j] = c;
                    }
                }
            }
            result++;
        }
        return 0;
	}

	void do_test(_0127_word_ladder* sol)
	{
		string beginWord1 = "hit";
		string endWord1 = "cog";
		vector<string> wordList1 = { "hot", "dot", "dog", "lot", "log", "cog" };
		int ret1 = sol->ladderLength(beginWord1, endWord1, wordList1);
		cout << ret1 << endl;
		// Output : 5
		// Explanation : One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog"->cog", 
		// which is 5 words long.

		string beginWord2 = "hit";
		string endWord2 = "cog";
		vector<string> wordList2 = { "hot", "dot", "dog", "lot", "log" };
		int ret2 = sol->ladderLength(beginWord2, endWord2, wordList2);
		cout << ret2 << endl;
		// Output : 0
		// Explanation : The endWord "cog" is not in wordList, 
		// therefore there is no valid transformation sequence.
	}
};
