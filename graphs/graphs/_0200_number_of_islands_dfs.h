#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0200_number_of_islands_dfs
{
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int result = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, m, n);
                    result++;
                }
            }
        }

        return result;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';

        dfs(grid, i - 1, j, m, n);
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i, j - 1, m, n);
        dfs(grid, i, j + 1, m, n);
    }

	void do_test(_0200_number_of_islands_dfs* sol)
	{
		vector<vector<char>> grid1 = { {'1', '1', '1', '1', '0'},
									   {'1', '1', '0', '1', '0'},
									   {'1', '1', '0', '0', '0'},
									   {'0', '0', '0', '0', '0'}};
		int ret1 = sol->numIslands(grid1);
		cout << ret1 << endl;
		//Output : 1
		

		vector<vector<char>> grid2 = { {'1', '1', '0', '0', '0'},
									   {'1', '1', '0', '0', '0'},
									   {'0', '0', '1', '0', '0'},
									   {'0', '0', '0', '1', '1'} };
		int ret2 = sol->numIslands(grid2);
		cout << ret2 << endl;
		//Output : 3
	}
};
