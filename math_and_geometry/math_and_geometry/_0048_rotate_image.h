#pragma once

#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;


class _0048_rotate_image
{
public:
	void rotate(vector<vector<int>>& matrix) {
		// 因為題目說是 n x n，所以其實用 left/right 然後 assign給 top/bottom 就可以了
		int n = matrix.size();
		//int left = 0, top = 0, right = n - 1, bottom = n - 1;
		int left = 0, right = n - 1;
		// while (top < bottom && left < right) {
		while (left < right) {
			int top = left;
			int bottom = right;
			for (int i = 0; i < right - left; i++) {
				int tmp = matrix[top][left + i];
				matrix[top][left + i] = matrix[bottom - i][left];
				matrix[bottom - i][left] = matrix[bottom][right - i];
				matrix[bottom][right - i] = matrix[top + i][right];
				matrix[top + i][right] = tmp;
			}
			//top += 1;
			left += 1;
			right -= 1;
			//bottom -= 1;
		}
	}

	/*
	// Given a 2D image matrix, rotate image 90 deg CW
    // Transpose + reflect (rev on diag then rev left to right)

	void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
	*/

	void do_test(_0048_rotate_image* sol) {
		vector<vector<int>> matrix;
		matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
		sol->rotate(matrix);
		print_vector_of_vector(matrix);
		// Output : {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}

		matrix = { {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16} };
		sol->rotate(matrix);
		print_vector_of_vector(matrix);
		// Output : {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}}
	}
};
