#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _1584_min_cost_to_connect_all_points
{
public:
	int minCostConnectPoints(vector<vector<int>>& points) {
		return 0;
	}

	void do_test(_1584_min_cost_to_connect_all_points* sol)
	{
		vector<vector<int>> points1 = { {0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0} };
		int ret1 = sol->minCostConnectPoints(points1);
		cout << ret1 << endl;
		// Output : 20

		vector<vector<int>> points2 = { {3, 12}, {-2, 5}, {-4, 1} };
		int ret2 = sol->minCostConnectPoints(points2);
		cout << ret2 << endl;
		// Output : 18
	}
};
