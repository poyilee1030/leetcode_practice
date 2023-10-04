#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class _0212_word_search_ii
{
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

	}

	void do_test(_0212_word_search_ii* sol)
	{
		vector<vector<char>> board1 = { {'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'},
									   {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'} };
		vector<string> words1 = {"oath", "pea", "eat", "rain"};
		vector<string> ret1 = findWords(board1, words1);
		//Output: ['eat', 'oath']


		vector<vector<char>> board2 = { {'a', 'b'}, {'c', 'd'} };
		vector<string> words2 = { "abcb" };
		vector<string> ret2 = findWords(board2, words2);
		//Output: []
	}

	void print_res(vector<string>& res)
	{
		cout << "[";
		for (int i = 0; i < res.size(); ++i)
		{
			cout << res[i];
			if (i != res.size() - 1)
			{
				cout << ",";
			}
		}
		cout << "]" << endl;
	}
};

