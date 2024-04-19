#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0200_number_of_islands_dfs
{
public:
    int rows, cols;
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int ans = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    dfs(grid, r, c);
                    ans += 1;
                }
            }
        }
        return ans;
    }

    // 一般來說可以另外開個 visit 來記錄走過的位置
    // 這裡直接把 '1' 改成 '#' 效率更好
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return;
        }

        if (grid[r][c] == '1') {
            grid[r][c] = '#';
            dfs(grid, r + 1, c);
            dfs(grid, r - 1, c);
            dfs(grid, r, c + 1);
            dfs(grid, r, c - 1);
        }
    }

	void do_test(_0200_number_of_islands_dfs* sol) {
        vector<vector<char>> grid;
        int ret;

		grid = { {'1', '1', '1', '1', '0'},
 			     {'1', '1', '0', '1', '0'},
				 {'1', '1', '0', '0', '0'},
				 {'0', '0', '0', '0', '0'}};
		ret = sol->numIslands(grid);
		cout << ret << endl;
		//Output : 1
		

		grid = { {'1', '1', '0', '0', '0'},
			     {'1', '1', '0', '0', '0'},
				 {'0', '0', '1', '0', '0'},
				 {'0', '0', '0', '1', '1'} };
		ret = sol->numIslands(grid);
		cout << ret << endl;
		//Output : 3
	}
};
