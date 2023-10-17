#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0695_max_area_of_island_dfs
{
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int result = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    result = max(result, dfs(grid, i, j, m, n));
                }
            }
        }

        return result;
    }

    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;

        return 1 + dfs(grid, i - 1, j, m, n) + dfs(grid, i + 1, j, m, n)
            + dfs(grid, i, j - 1, m, n) + dfs(grid, i, j + 1, m, n);
    }

	void do_test(_0695_max_area_of_island_dfs* sol)
	{
        vector<vector<int>> grid1 = { {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                      {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                      {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                      {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
                                      {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, 
                                      {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0} };
        int ret1 = sol->maxAreaOfIsland(grid1);
        cout << ret1 << endl;
        //Output : 6
        //Explanation : The answer is not 11, because the island must be connected 4 - directionally.
        

        vector<vector<int>> grid2 = { {0, 0, 0, 0, 0, 0, 0, 0} };
        int ret2 = sol->maxAreaOfIsland(grid2);
        cout << ret2 << endl;
        //Output : 0
	}
};


