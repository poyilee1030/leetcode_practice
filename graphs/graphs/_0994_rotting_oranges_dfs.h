#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0994_rotting_oranges_dfs
{
public:
	int orangesRotting(vector<vector<int>>& grid) {

	}

	void do_test(_0994_rotting_oranges_dfs* sol)
	{
		vector<vector<int>> grid1 = { {2, 1, 1},{1, 1, 0},{0, 1, 1} };
		int ret1 = sol->orangesRotting(grid1);
		cout << ret1 << endl;
		// Output : 4
		

		vector<vector<int>> grid2 = { {2, 1, 1},{0, 1, 1},{1, 0, 1} };
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
