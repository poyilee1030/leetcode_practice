#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0684_redundant_connection
{
public:
    unordered_map<int, int> Father;

    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        for (auto edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            if (Father.find(a)==Father.end())
                Father[a] = a;
            if (Father.find(b) == Father.end())
                Father[b] = b;

            if (FindFather(a) == FindFather(b))
                return edge;
            else
                Union(a, b);
        }
        return {};
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

	void do_test(_0684_redundant_connection* sol)
	{
		vector<vector<int>> edges1 = { {1, 2}, {1, 3}, {2, 3} };
		vector<int> ret1 = sol->findRedundantConnection(edges1);
		print_res(ret1);
		// Output : [2, 3]

        sol->Father.clear();

		vector<vector<int>> edges2 = { {1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5} };
		vector<int> ret2 = sol->findRedundantConnection(edges2);
		print_res(ret2);
		// Output : [1, 4]
	}

	void print_res(vector<int> res)
	{
		cout << "[";
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i];
			if (i < res.size() - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}
};
