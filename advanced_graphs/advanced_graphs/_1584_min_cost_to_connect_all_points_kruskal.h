#pragma once

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class _1584_min_cost_to_connect_all_points_kruskal
{
    int Father[1000];

    int findFather(int x)
    {
        if (Father[x] != x)
            Father[x] = findFather(Father[x]);
        return Father[x];
    }

    void Union(int x, int y)
    {
        x = Father[x];
        y = Father[y];
        if (x < y) Father[y] = x;
        else Father[x] = y;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        int n = points.size();
        for (int i = 0; i < n; i++)
            Father[i] = i;

        // array<int, 3> 似乎是 c++ 17 才有支援
        // 在 leetcode 上可以使用 array<int, 3> 取代 vector<int>
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> edges;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push({ dis, i, j });
            }

        int result = 0;
        int count = 1;

        while (count < n)
        {
            auto edge = edges.top();
            edges.pop();
            int a = edge[1];
            int b = edge[2];
            int dis = edge[0];
            if (findFather(a) != findFather(b))
            {
                Union(a, b);
                count++;
                result += dis;
                if (count == n) break;
            }
        }

        return result;
    }

	void do_test(_1584_min_cost_to_connect_all_points_kruskal* sol) {
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
