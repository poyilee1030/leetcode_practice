#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class _0079_word_search
{
public:
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		int n = board[0].size();

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == word[0]) {
					if (dfs(board, word, 0, i, j, m, n)) {
						return true;
					}
				}
			}
		}

		return false;
	}

	bool dfs(vector<vector<char>>& board, string word,
		int index, int i, int j, int m, int n) {

		if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) {
			return false;
		}
		if (index == word.size() - 1) {
			return true;
		}

		board[i][j] = '#';

		if (dfs(board, word, index + 1, i - 1, j, m, n)
			|| dfs(board, word, index + 1, i + 1, j, m, n)
			|| dfs(board, word, index + 1, i, j - 1, m, n)
			|| dfs(board, word, index + 1, i, j + 1, m, n)) {
			return true;
		}

		board[i][j] = word[index];
		return false;
	}

	void do_test(_0079_word_search* sol)
	{
		vector<vector<char>> board1 = { {'A', 'B', 'C', 'E'}, 
										{'S', 'F', 'C', 'S'}, 
			                            {'A', 'D', 'E', 'E'} };
		string word1 = "ABCCED";
		bool res1 = sol->exist(board1, word1);
		cout << res1 << endl;
		//Output : true

		vector<vector<char>> board2 = { {'A', 'B', 'C', 'E'},
										{'S', 'F', 'C', 'S'},
										{'A', 'D', 'E', 'E'} };
		string word2 = "SEE";
		bool res2 = sol->exist(board2, word2);
		cout << res2 << endl;
		//Output : true

		vector<vector<char>> board3 = { {'A', 'B', 'C', 'E'},
										{'S', 'F', 'C', 'S'},
										{'A', 'D', 'E', 'E'} };
		string word3 = "ABCB";
		bool res3 = sol->exist(board3, word3);
		cout << res3 << endl;
		//Output : false
	}
};


