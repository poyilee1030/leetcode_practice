#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class _0787_cheapest_flights_within_k_stops
{
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		return 0;
	}

	void do_test(_0787_cheapest_flights_within_k_stops* sol)
	{
		int n1 = 4;
		vector<vector<int>> flights1 = { {0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200} };
		int src1 = 0;
		int dst1 = 3;
		int k1 = 1;
		int ret1 = sol->findCheapestPrice(n1, flights1, src1, dst1, k1);
		cout << ret1 << endl;
		/*
		Output : 700
		Explanation :
		The graph is shown above.
		The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
		Note that the path through cities[0, 1, 2, 3] is cheaper but is invalid because it uses 2 stops.
		*/
		
		int n2 = 3;
		vector<vector<int>> flights2 = { {0, 1, 100}, {1, 2, 100}, {0, 2, 500} };
		int src2 = 0;
		int dst2 = 2;
		int k2 = 1;
		int ret2 = sol->findCheapestPrice(n2, flights2, src2, dst2, k2);
		cout << ret2 << endl;
		/*
		Output : 200
		Explanation :
		The graph is shown above.
		The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
		*/
		
		int n3 = 3;
		vector<vector<int>> flights3 = { {0, 1, 100}, {1, 2, 100}, {0, 2, 500} };
		int src3 = 0;
		int dst3 = 2;
		int k3 = 0;
		int ret3 = sol->findCheapestPrice(n3, flights3, src3, dst3, k3);
		cout << ret3 << endl;
		/*
		Output : 500
		Explanation :
		The graph is shown above.
		The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
		*/
		
	}
};

