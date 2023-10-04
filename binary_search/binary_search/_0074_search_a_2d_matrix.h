#pragma once

#include <iostream>
#include <vector>

using namespace std;

class _0074_search_a_2d_matrix
{
public:

	bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int total = row * col;
        int i = 0;
        int j = total - 1;
        // 總是使用 l <= r, 少了=會需要多考慮一些 edge case
        while (i <= j)
        {
            int m = i + (j - i + 1) / 2;
            int r = m / col;
            int c = m % col;
            if (matrix[r][c] > target)
            {
                j = m - 1;
            }
            else if (matrix[r][c] < target)
            {
                i = m + 1;
            }
            else
            {
                return true;
            }
        }
        return false;
	}

	void do_test(_0074_search_a_2d_matrix *sol)
	{
		vector<vector<int>> matrix1 = { {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60} };
		int target1 = 3;
		bool ret1 = sol->searchMatrix(matrix1, target1);
		cout << ret1 << endl;
		//Output : true

		vector<vector<int>> matrix2 = { {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60} };
		int target2 = 13;
		bool ret2 = sol->searchMatrix(matrix2, target2);
		cout << ret2 << endl;
		//Output : false

        vector<vector<int>> matrix3 = { {1, 3} };
        int target3 = 1;
        bool ret3 = sol->searchMatrix(matrix3, target3);
        cout << ret3 << endl;
        //Output : true

        vector<vector<int>> matrix4 = { {1, 3, 5} };
        int target4 = 5;
        bool ret4 = sol->searchMatrix(matrix4, target4);
        cout << ret4 << endl;
        //Output : true
	}
};
