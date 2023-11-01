#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0048_rotate_image
{
public:
	void rotate(vector<vector<int>>& matrix) {

	}

	void do_test(_0048_rotate_image* sol) {
		vector<vector<int>> matrix1 = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
		sol->rotate(matrix1);
		print_res(matrix1);
		// Output : {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}


		vector<vector<int>> matrix2 = { {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16} };
		sol->rotate(matrix2);
		print_res(matrix2);
		// Output : {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}}
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
