#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class _0127_word_ladder
{
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
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
