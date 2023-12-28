#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0054_spiral_matrix
{
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int bottom = matrix.size();
        int left = 0;
        int right = matrix[0].size();

        vector<int> output;
        while (left < right && top < bottom) {
            for (int i = left; i < right; i++) {
                output.push_back(matrix[top][i]);
            }
            top++;

            for (int j = top; j < bottom; j++) {
                output.push_back(matrix[j][right-1]);
            }
            right--;

            if (left >= right || top >= bottom)
                break;

            for (int i = right - 1; i >= left; i--) {
                output.push_back(matrix[bottom - 1][i]);
            }
            bottom--;

            for (int j = bottom - 1; j >= top; j--) {
                output.push_back(matrix[j][left]);
            }
            left++;
        }
        return output;
	}

	void do_test(_0054_spiral_matrix* sol) {
		vector<vector<int>> matrix1 = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
		vector<int> ret1 = sol->spiralOrder(matrix1);
		print_res(ret1);
		// Output : [1, 2, 3, 6, 9, 8, 7, 4, 5]
		
		vector<vector<int>> matrix2 = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
		vector<int> ret2 = sol->spiralOrder(matrix2);
		print_res(ret2);
		// Output : [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
	}

	void print_res(vector<int> res) {
		cout << "[";
		for (int i = 0; i < res.size(); i++) {
			cout << res[i];
			if (i < res.size() - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}
};
