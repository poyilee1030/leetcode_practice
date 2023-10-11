#pragma once

#include <iostream>
#include <vector>

using namespace std;

class _0036_valid_sudoku
{
public:
	bool isValidSudoku(vector<vector<char>>& board)
	{
		const int cnt = 9;
		bool row[cnt][cnt] = { false };
		bool col[cnt][cnt] = { false };
		bool sub[cnt][cnt] = { false };

		for (int r = 0; r < cnt; ++r) {
			for (int c = 0; c < cnt; ++c) {
				if (board[r][c] == '.')
					continue; // if not number pass

				int idx = board[r][c] - '0' - 1; //char to num idx
				int area = (r / 3) * 3 + (c / 3);

				//if number already exists
				if (row[r][idx] || col[c][idx] || sub[area][idx]) {
					return false;
				}

				row[r][idx] = true;
				col[c][idx] = true;
				sub[area][idx] = true;
			}
		}
		return true;
	}

	void do_test(_0036_valid_sudoku* sol)
	{
		// "." is not a char, must use '.' to represent a dot
		vector<vector<char>> board1 =
		{ {'5', '3', '.', '.', '7', '.', '.', '.', '.'}
		, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
		, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
		, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
		, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
		, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
		, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
		, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
		, {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
		bool ret1 = sol->isValidSudoku(board1);
		cout << ret1 << endl;
		//Output: true

		vector<vector<char>> board2 =
		{ {'8', '3', '.', '.', '7', '.', '.', '.', '.'}
		, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
		, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
		, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
		, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
		, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
		, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
		, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
		, {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
		bool ret2 = sol->isValidSudoku(board2);
		cout << ret2 << endl;
		//Output: false

	}
};




