#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0778_swim_in_rising_water
{
public:
	int swimInWater(vector<vector<int>>& grid) {
		return 0;
	}

	void do_test(_0778_swim_in_rising_water* sol)
	{
		vector<vector<int>> grid1 = { {0, 2},
									  {1, 3} };
		int ret1 = sol->swimInWater(grid1);
		cout << ret1 << endl;
		/*
		Output : 3
		Explanation :
		At time 0, you are in grid location(0, 0).
		You cannot go anywhere else because 4 - directionally adjacent neighbors have a higher elevation than t = 0.
		You cannot reach point(1, 1) until time 3.
		When the depth of water is 3, we can swim anywhere inside the grid.
		*/
		
		vector<vector<int>> grid2 = { { 0,  1,  2,  3,  4}, 
									  {24, 23, 22, 21,  5}, 
									  {12, 13, 14, 15, 16}, 
									  {11, 17, 18, 19, 20}, 
									  {10,  9,  8,  7,  6} };
		int ret2 = sol->swimInWater(grid2);
		cout << ret2 << endl;
		/*
		Output : 16
		Explanation : The final route is shown.
		We need to wait until time 16 so that(0, 0) and (4, 4) are connected.
		*/
		
	}
};
