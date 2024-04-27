#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _1584_min_cost_to_connect_all_points_prim
{
public:
	int minCostConnectPoints(vector<vector<int>>& points) {
		return 0;
	}

	void do_test(_1584_min_cost_to_connect_all_points_prim* sol) {
		vector<vector<int>> points;
		int ret;

		points = { {0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0} };
		ret = sol->minCostConnectPoints(points);
		cout << ret << endl;
		// Output : 20

		points = { {3, 12}, {-2, 5}, {-4, 1} };
		ret = sol->minCostConnectPoints(points);
		cout << ret << endl;
		// Output : 18
	}
};
