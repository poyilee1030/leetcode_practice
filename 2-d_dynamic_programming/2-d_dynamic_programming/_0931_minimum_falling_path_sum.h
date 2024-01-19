#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class _0931_minimum_falling_path_sum
{
    int n;
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        auto dp = matrix;        // dp[i][j]: minimum sum of a falling path through matrix to (i,j)
        n = matrix.size();

        for (int c = 0; c < n; c++)
            dp[0][c] = matrix[0][c];

        for (int r = 1; r < n; r++) {
            for (int c = 0; c < n; c++) {
                dp[r][c] = INT_MAX;
                for (int k = c - 1; k <= c + 1; k++) {
                    if (k < 0 || k >= n)
                        continue;
                    dp[r][c] = min(dp[r][c], dp[r - 1][k] + matrix[r][c]);
                }
            }
        }
            
        int ret = INT_MAX;
        for (int c = 0; c < n; c++)
            ret = min(ret, dp[n - 1][c]);
        
        return ret;
    }
    /*
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        vector<unordered_map<int, int>> cache(n);
        
        int ans = INT_MAX;
        for (int c = 0; c < n; c++) {
            ans = min(ans, dfs(matrix, 0, c, cache));
        }
        return ans;
    }

    int dfs(vector<vector<int>>& matrix, int r, int c, vector<unordered_map<int, int>> &cache) {
        if (c < 0 || c >= n) {
            return INT_MAX;
        }
        if (r >= n) {
            return 0;
        }

        if (cache[r].find(c) != cache[r].end()) {
            return cache[r][c];
        }
        int left = dfs(matrix, r + 1, c - 1, cache);
        int mid = dfs(matrix, r + 1, c, cache);
        int right = dfs(matrix, r + 1, c + 1, cache);

        int result = min(min(left, mid), right) + matrix[r][c];
        cache[r][c] = result;

        return result;
    }
    */
    

	void do_test(_0931_minimum_falling_path_sum* sol) {
		vector<vector<int>> matrix1 = { {2, 1, 3}, {6, 5, 4}, {7, 8, 9} };
		int ret1 = sol->minFallingPathSum(matrix1);
		cout << ret1 << endl;
		// Output: 13
		
		vector<vector<int>> matrix2 = { {-19, 57}, {-40, -5} };
		int ret2 = sol->minFallingPathSum(matrix2);
		cout << ret2 << endl;
		// Output: -59
	}
};
