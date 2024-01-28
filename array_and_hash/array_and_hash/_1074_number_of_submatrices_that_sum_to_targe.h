#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
    Time complexity: O(n^3)
*/


class _1074_number_of_submatrices_that_sum_to_targe
{
public:
    // by Guan
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int count = 0;

        for (int r1 = 0; r1 < rows; r1++) {
            vector<int> row(cols);
            for (int r2 = r1; r2 < rows; r2++) {
                for (int c = 0; c < cols; c++)
                    row[c] += matrix[r2][c];

                unordered_map<int, int> presumMap;
                presumMap[0] = 1;
                int presum = 0;
                for (int c = 0; c < cols; c++)
                {
                    presum += row[c];
                    // 因為 unordered_map default = 0，所以其實下面這個 if 不寫也可以
                    if (presumMap.find(presum - target) != presumMap.end())
                        count += presumMap[presum - target];
                    presumMap[presum] += 1;
                }
            }
        }
        return count;
    }

    /* by neetcode
    int rows, cols;
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        rows = matrix.size();
        cols = matrix[0].size();
        vector<vector<int>> sub_sum(rows, vector<int>(cols));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int top = 0;
                if (r > 0)
                    top = sub_sum[r-1][c];
                
                int left = 0;
                if (c > 0)
                    left = sub_sum[r][c-1];
                
                int left_top = 0;
                if (min(r, c) > 0)
                    left_top = sub_sum[r-1][c-1];
                sub_sum[r][c] = matrix[r][c] + top + left - left_top;
            }
        }

        int res = 0;
        for (int r1 = 0; r1 < rows; r1++) {
            for (int r2 = r1; r2 < rows; r2++) {
                for (int c1 = 0; c1 < cols; c1++) {
                    for (int c2 = c1; c2 < cols; c2++) {
                        int top = 0;
                        if (r1 > 0)
                            top = sub_sum[r1-1][c2];
                        
                        int left = 0;
                        if (c1 > 0)
                            left = sub_sum[r2][c1-1];
                        
                        int left_top = 0;
                        if (min(r1, c1) > 0)
                            left_top = sub_sum[r1-1][c1-1];
                        int cur_sum = sub_sum[r2][c2] - top - left + left_top;
                        if (cur_sum == target)
                            res++;
                    }
                }
            }
        }
        return res;
    }
    */

	void do_test(_1074_number_of_submatrices_that_sum_to_targe* sol) {
        vector<vector<int>> matrix1 = { {0, 1, 0}, {1, 1, 1}, {0, 1, 0} };
        int ret1 = sol->numSubmatrixSumTarget(matrix1, 0);
        cout << ret1 << endl;
        // Output : 4
        
        vector<vector<int>> matrix2 = { {1, -1}, {-1, 1} };
        int ret2 = sol->numSubmatrixSumTarget(matrix2, 0);
        cout << ret2 << endl;
        // Output : 5

        vector<vector<int>> matrix3 = { {904} };
        int ret3 = sol->numSubmatrixSumTarget(matrix3, 0);
        cout << ret3 << endl;
        // Output : 0
	}
};
