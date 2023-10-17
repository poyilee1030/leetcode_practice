#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0695_max_area_of_island_bfs
{
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        return 0;
    }

	void do_test(_0695_max_area_of_island_bfs* sol)
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


