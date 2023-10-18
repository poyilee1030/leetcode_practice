#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "define.h"

using namespace std;


class _0212_word_search_ii
{
	TrieNode* root = new TrieNode();

public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		for (int i = 0; i < words.size(); i++) {
			insert(words[i]);
		}

		int m = board.size();
		int n = board[0].size();

		TrieNode* node = root;
		vector<string> result;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				search(board, i, j, m, n, node, "", result);
			}
		}

		return result;
	}

	void insert(string word) {
		TrieNode* node = root;
		int curr = 0;

		for (int i = 0; i < word.size(); i++) {
			curr = word[i] - 'a';
			if (node->children[curr] == NULL) {
				node->children[curr] = new TrieNode();
			}
			node = node->children[curr];
		}

		node->isWord = true;
	}

	void search(vector<vector<char>>& board, int i, int j, int m, int n, TrieNode* node, string word, vector<string>& result) {
		if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#') {
			return;
		}

		char c = board[i][j];

		node = node->children[c - 'a'];
		if (node == NULL) {
			return;
		}

		word += board[i][j];
		if (node->isWord) {
			result.push_back(word);
			node->isWord = false;
		}

		board[i][j] = '#';

		search(board, i - 1, j, m, n, node, word, result);
		search(board, i + 1, j, m, n, node, word, result);
		search(board, i, j - 1, m, n, node, word, result);
		search(board, i, j + 1, m, n, node, word, result);

		board[i][j] = c;
	}

	void do_test(_0212_word_search_ii* sol)
	{
		vector<vector<char>> board1 = { {'o', 'a', 'a', 'n'}, 
										{'e', 't', 'a', 'e'},
									    {'i', 'h', 'k', 'r'}, 
										{'i', 'f', 'l', 'v'} };
		vector<string> words1 = { "oath", "pea", "eat", "rain" };
		vector<string> ret1 = findWords(board1, words1);
		print_res(ret1);
		//Output: ['eat', 'oath']

		vector<vector<char>> board2 = { {'a', 'b'}, {'c', 'd'} };
		vector<string> words2 = { "abcb" };
		vector<string> ret2 = findWords(board2, words2);
		print_res(ret2);
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
