#pragma once


class _0576_out_of_boundary_paths
{
public:
    int dp[51][51][51];
    int mod = 1000000007;
    int dfs(int m, int n, int maxMove, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return 1;
        }
        if (maxMove <= 0) {
            return 0;
        }
        if (dp[i][j][maxMove] != -1) {
            return dp[i][j][maxMove];
        }
        long up = dfs(m, n, maxMove - 1, i - 1, j);
        long down = dfs(m, n, maxMove - 1, i + 1, j);
        long right = dfs(m, n, maxMove - 1, i, j + 1);
        long left = dfs(m, n, maxMove - 1, i, j - 1);
        return dp[i][j][maxMove] = ((up + down) % mod + (right + left) % mod) % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return dfs(m, n, maxMove, startRow, startColumn);
    }
    /*
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        unordered_map<string, long> cache;
        return dfs(m, n, maxMove, startRow, startColumn, cache);
    }

    int dfs(int m, int n, int remainMove, int curRow, int curCol, unordered_map<string, long>& cache) {
        if (curRow < 0 || curRow >= m || curCol < 0 || curCol >= n) {
            return 1;
        }
        if (remainMove <= 0) {
            return 0;
        }

        string key = makeKey(remainMove, curRow, curCol);
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        int left = dfs(m, n, remainMove - 1, curRow, curCol - 1, cache);
        int right = dfs(m, n, remainMove - 1, curRow, curCol + 1, cache);
        int top = dfs(m, n, remainMove - 1, curRow - 1, curCol, cache);
        int down = dfs(m, n, remainMove - 1, curRow + 1, curCol, cache);
        long mod = 1e9 + 7;
        cache[key] = ((left + right) % mod + (top + down) % mod) % mod;
        return cache[key];
    }

    string makeKey(int move, int row, int col) {
        string s = to_string(move) + "," + to_string(row) + "," + to_string(col);
        return s;
    }
    */
    

	void do_test(_0576_out_of_boundary_paths* sol) {
        int ret1 = sol->findPaths(2, 2, 2, 0, 0);
        cout << ret1 << endl;
        // Output: 6

        int ret2 = sol->findPaths(1, 3, 3, 0, 1);
        cout << ret2 << endl;
        // Output: 12

        int ret3 = sol->findPaths(8, 50, 23, 5, 26);
        cout << ret3 << endl;
        // Output: 914783380
	}
};
