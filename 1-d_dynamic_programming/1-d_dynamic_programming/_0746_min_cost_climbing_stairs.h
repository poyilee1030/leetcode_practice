#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0746_min_cost_climbing_stairs
{
public:
	int minCostClimbingStairs(vector<int>& cost) {
		cost.push_back(0);

		for (int i = cost.size() - 3; i >= 0; i--)
		{
			cost[i] += min(cost[i + 1], cost[i + 2]);
		}
		return min(cost[0], cost[1]);
	}

	void do_test(_0746_min_cost_climbing_stairs* sol)
	{
		vector<int> cost1 = { 10, 15, 20 };
		int ret1 = sol->minCostClimbingStairs(cost1);
		cout << ret1 << endl;
		/*
		Output : 15
		Explanation : You will start at index 1.
		- Pay 15 and climb two steps to reach the top.
		The total cost is 15.
		*/
		
		vector<int> cost2 = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
		int ret2 = sol->minCostClimbingStairs(cost2);
		cout << ret2 << endl;
		/*
		Output : 6
		Explanation : You will start at index 0.
		- Pay 1 and climb two steps to reach index 2.
		- Pay 1 and climb two steps to reach index 4.
		- Pay 1 and climb two steps to reach index 6.
		- Pay 1 and climb one step to reach index 7.
		- Pay 1 and climb two steps to reach index 9.
		- Pay 1 and climb one step to reach the top.
		The total cost is 6.
		*/
	}
};


