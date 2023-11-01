#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0073_set_matrix_zeroes
{
public:
	void setZeroes(vector<vector<int>>& matrix) {

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
