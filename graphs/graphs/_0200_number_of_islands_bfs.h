#pragma once

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class _0200_number_of_islands_bfs
{
public:
    int numIslands(vector<vector<char>>& grid) {
        int M = grid.size();
        int N = grid[0].size();

        if (M == 0) 
            return 0;

        auto visited = vector<vector<int>>(M, vector<int>(N, 0));
        auto dir = vector<pair<int, int>>{ {0,1},{0,-1},{1,0},{-1,0} };

        int count = 0;
        queue<pair<int, int>>q;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == '0' || visited[i][j] == 1)
                    continue;

                visited[i][j] = 1;
                q.push({ i,j });
                count++;

                while (!q.empty())
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int m = q.front().first + dir[k].first;
                        int n = q.front().second + dir[k].second;
                        if (m >= 0 && m < M && n >= 0 && n < N && visited[m][n] == 0 && grid[m][n] == '1')
                        {
                            q.push({ m,n });
                            visited[m][n] = 1;
                        }
                    }
                    q.pop();
                }
            }

        return count;
    }

	void do_test(_0200_number_of_islands_bfs* sol)
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
