#pragma once

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
    Given grid: 0 empty cell, 1 fresh orange, 2 rotten orange
    Return min # of minutes until no cell has a fresh orange

    BFS: rotten will contaminate neighbors first, then propagate out

    Time: O(m x n)
    Space: O(m x n)
*/

class _0994_rotting_oranges
{
    vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

public:
	int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        int time = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 2) {
                    q.push({ r, c });
                }
                else if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }

        // start rotting process via BFS
        while (!q.empty() && fresh > 0) {
            int length = q.size();
            for (int i = 0; i < length; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                // rotten orange, contaminate its neighbors
                for (int j = 0; j < dirs.size(); j++) {
                    int x = row + dirs[j][0];
                    int y = col + dirs[j][1];

                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        continue;
                    }

                    if (grid[x][y] == 1) {
                        // contaminate
                        grid[x][y] = 2;
                        fresh--;
                        // this orange will now contaminate others
                        q.push({ x, y });
                    }
                }
            }
            time++;
        }

        if (fresh == 0) {
            return time;
        }
        return -1;
	}

	void do_test(_0994_rotting_oranges* sol)
	{
        vector<vector<int>> grid0 = { {2, 1, 1},
                                      {1, 1, 1},
                                      {0, 1, 2} };
        int ret0 = sol->orangesRotting(grid0);
        cout << ret0 << endl;
        // Output : 2

		vector<vector<int>> grid1 = { {2, 1, 1},
                                      {1, 1, 0},
                                      {0, 1, 1} };
		int ret1 = sol->orangesRotting(grid1);
		cout << ret1 << endl;
		// Output : 4
		

		vector<vector<int>> grid2 = { {2, 1, 1},
                                      {0, 1, 1},
                                      {1, 0, 1} };
		int ret2 = sol->orangesRotting(grid2);
		cout << ret2 << endl;
		// Output : -1
		// Explanation : The orange in the bottom left corner(row 2, column 0) is never rotten, 
		// because rotting only happens 4 - directionally.
		

		vector<vector<int>> grid3 = { {0, 2} };
		int ret3 = sol->orangesRotting(grid3);
		cout << ret3 << endl;
		// Output : 0
		// Explanation : Since there are already no fresh oranges at minute 0, the answer is just 0.
	}
};
