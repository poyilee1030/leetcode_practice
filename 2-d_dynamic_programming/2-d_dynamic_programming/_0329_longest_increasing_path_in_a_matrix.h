#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class _0329_longest_increasing_path_in_a_matrix
{
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		return 0;
	}

	void do_test(_0329_longest_increasing_path_in_a_matrix* sol) {
		vector<vector<int>> matrix1 = { {9, 9, 4}, {6, 6, 8}, {2, 1, 1} };
		int ret1 = sol->longestIncreasingPath(matrix1);
		cout << ret1 << endl;
		// Output : 4
		// Explanation : The longest increasing path is[1, 2, 6, 9].

		vector<vector<int>> matrix2 = { {3, 4, 5}, {3, 2, 6}, {2, 2, 1} };
		int ret2 = sol->longestIncreasingPath(matrix2);
		cout << ret2 << endl;
		// Output : 4
		// Explanation : The longest increasing path is[3, 4, 5, 6].Moving diagonally is not allowed.
		

		vector<vector<int>> matrix3 = { {1} };
		int ret3 = sol->longestIncreasingPath(matrix3);
		cout << ret3 << endl;
		// Output : 1
	}
};
