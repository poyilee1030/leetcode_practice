#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0130_surrounded_regions_dfs
{
public:
	void solve(vector<vector<char>>& board)
	{
        int m = board.size();
        int n = board[0].size();

        // marking escaped cells along the border
        for (int i = 0; i < m; i++) {
            dfs(board, i, 0, m, n);
            dfs(board, i, n - 1, m, n);
        }

        for (int j = 0; j < n; j++) {
            dfs(board, 0, j, m, n);
            dfs(board, m - 1, j, m, n);
        }

        // flip cells to correct final states
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'E') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j, int m, int n)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
            return;
        }

        board[i][j] = 'E';

        dfs(board, i - 1, j, m, n);
        dfs(board, i + 1, j, m, n);
        dfs(board, i, j - 1, m, n);
        dfs(board, i, j + 1, m, n);
	}

	void do_test(_0130_surrounded_regions_dfs* sol)
	{
		vector<vector<char>> board1 = { {'X', 'X', 'X', 'X'},
										{'X', 'O', 'O', 'X'},
										{'X', 'X', 'O', 'X'},
										{'X', 'O', 'X', 'X'} };
        sol->solve(board1);
        print_res(board1);
        
		/*
		Output : [['X', 'X', 'X', 'X'],
		          ['X', 'X', 'X', 'X'],
				  ['X', 'X', 'X', 'X'],
				  ['X', 'O', 'X', 'X']]
		Explanation : Notice that an 'O' should not be flipped if :
		-It is on the border, or
		-It is adjacent to an 'O' that should not be flipped.
		The bottom 'O' is on the border, so it is not flipped.
		The other three 'O' form a surrounded region, so they are flipped.
		*/
		
		vector<vector<char>> board2 = { {'X'} };
        sol->solve(board2);
        print_res(board2);
		//Output : [['X']]
	}

    void print_res(vector<vector<char>>& res)
    {
        cout << "[";
        for (int i = 0; i < res.size(); i++)
        {
            cout << "[";
            vector<char> oo = res[i];
            for (int j = 0; j < oo.size(); j++)
            {
                cout << oo[j];
                if (j < oo.size() - 1)
                    cout << ",";
            }
            cout << "]";

            if (i < res.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }
};
