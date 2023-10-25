#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class _0261_graph_valid_tree
{
public:
	bool validTree(int n, vector<vector<int>>& edges) {
		return false;
	}

	void do_test(_0261_graph_valid_tree* sol)
	{
		int n1 = 5;
		vector<vector<int>> edges1 = { {0, 1}, {0, 2}, {0, 3}, {1, 4} };
		bool ret1 = sol->validTree(n1, edges1);
		cout << ret1 << endl;
		// Output : true

		int n2 = 5;
		vector<vector<int>> edges2 = { {0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4} };
		bool ret2 = sol->validTree(n2, edges2);
		cout << ret2 << endl;
		// Output : false
	}
};
