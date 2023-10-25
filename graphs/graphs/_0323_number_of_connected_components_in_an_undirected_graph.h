#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class _0323_number_of_connected_components_in_an_undirected_graph
{
	unordered_map<int, int> Father;
public:
	int countComponents(int n, vector<vector<int>>& edges) {

		int res = n;
		for (auto edge : edges)
		{
			int a = edge[0];
			int b = edge[1];
			if (Father.find(a) == Father.end())
				Father[a] = a;
			if (Father.find(b) == Father.end())
				Father[b] = b;

			if (FindFather(a) == FindFather(b)) {

			}
			else {
				Union(a, b);
				res--;
			}
		}
		return res;
	}

	int FindFather(int x)
	{
		if (Father[x] != x)
		{
			Father[x] = FindFather(Father[x]);
		}
		return Father[x];
	}

	void Union(int x, int y)
	{
		x = Father[x];
		y = Father[y];
		if (x < y)
			Father[y] = x;
		else
			Father[x] = y;
	}

	void do_test(_0323_number_of_connected_components_in_an_undirected_graph* sol)
	{
		int n1 = 5;
		vector<vector<int>> edges1 = { {0, 1}, {1, 2}, {3, 4} };
		int ret1 = sol->countComponents(n1, edges1);
		cout << ret1 << endl;
		// Output : 2

		sol->Father.clear();

		int n2 = 5;
		vector<vector<int>> edges2 = { {0, 1}, {1, 2}, {2, 3}, {3, 4} };
		int ret2 = sol->countComponents(n2, edges2);
		cout << ret2 << endl;
		// Output : 1
	}
};
