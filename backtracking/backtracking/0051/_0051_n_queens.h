#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


class _0051_n_queens
{
public:
    unordered_set<int> cols;     //for Columns
    unordered_set<int> negDiag;  //for negative diagnals R-C
    unordered_set<int> posDiag;  //for positive diagnals R+C

	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		vector<string> board(n, string(n, '.'));
		backtrack(n, 0, res, board);
		return res;
	}

    void backtrack(int n, int row, vector<vector<string>>& res, vector<string>& board) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {   //Shifting through each col
            if (cols.find(col) != cols.end() or //if queen alread placed in this col
                negDiag.find(row - col) != negDiag.end() or //if queen in negDiag
                posDiag.find(row + col) != posDiag.end()    //if queen in posDiag
                )
                continue;

            cols.insert(col);
            negDiag.insert(row - col);
            posDiag.insert(row + col);
            board[row][col] = 'Q';

            backtrack(n, row + 1, res, board);

            cols.erase(col);
            negDiag.erase(row - col);
            posDiag.erase(row + col);
            board[row][col] = '.';
        }
    }

	void do_test(_0051_n_queens* sol)
	{
		int n1 = 4;
		vector<vector<string>> res1 = sol->solveNQueens(n1);
		print_res(res1);
		//Output : [[".Q..", "...Q", "Q...", "..Q."], ["..Q.", "Q...", "...Q", ".Q.."]]
		//Explanation : There exist two distinct solutions to the 4 - queens puzzle as shown above
		
		int n2 = 1;
		vector<vector<string>> res2 = sol->solveNQueens(n2);
		print_res(res2);
		//Output : [["Q"]]
	}

	void print_res(vector<vector<string>> res)
	{
		cout << "[";
		for (int i = 0; i < res.size(); ++i)
		{
			cout << "[";
			vector<string> oo = res[i];
			for (int j = 0; j < oo.size(); ++j)
			{
				cout << oo[j];
				if (j != oo.size() - 1)
					cout << ",";
			}
			cout << "]";
			if (i != res.size() - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}
};
