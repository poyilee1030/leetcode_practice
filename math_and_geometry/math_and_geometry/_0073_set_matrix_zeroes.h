#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
    Given matrix, if element 0, set entire row/col to 0

    Use 1st row/col as flag to determine if entire row/col 0

    Time: O(mn)
    Space: O(1)
*/

class _0073_set_matrix_zeroes
{
public:
	void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool isFirstRowZero = false;
        bool isFirstColZero = false;

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                isFirstColZero = true;
                break;
            }
        }

        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                isFirstRowZero = true;
                break;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (isFirstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }

        if (isFirstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
	}

	void do_test(_0073_set_matrix_zeroes* sol) {
		vector<vector<int>> matrix1 = { {1, 1, 1}, {1, 0, 1}, {1, 1, 1} };
		sol->setZeroes(matrix1);
		print_res(matrix1);
		// Output : {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}

		vector<vector<int>> matrix2 = { {0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5} };
		sol->setZeroes(matrix2);
		print_res(matrix2);
		// Output : {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}}
	}

	void print_res(vector<vector<int>>& res) {
		cout << "[";
		for (int i = 0; i < res.size(); i++) {
			cout << "[";
			vector<int> oo = res[i];
			for (int j = 0; j < oo.size(); j++) {
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
