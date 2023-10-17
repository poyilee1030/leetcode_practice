#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0286_walls_and_gates_dfs
{
public:
	void wallsAndGates(vector<vector<int>>& rooms) {

	}

	void do_test(_0286_walls_and_gates_dfs* sol)
	{
		vector<vector<int>> rooms1 = { {2147483647, -1, 0, 2147483647},
									   {2147483647, 2147483647, 2147483647, -1},
									   {2147483647, -1, 2147483647, -1},
									   {0, -1, 2147483647, 2147483647} };
		sol->wallsAndGates(rooms1);
		// Output : {{3, -1, 0, 1}, {2, 2, 1, -1}, {1, -1, 2, -1}, {0, -1, 3, 4}}
		

		vector<vector<int>> rooms2 = { {-1} };
		sol->wallsAndGates(rooms2);
		// Output : {{-1}}
	}
};

