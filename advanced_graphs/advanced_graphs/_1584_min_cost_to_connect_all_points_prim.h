#pragma once

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define pii pair<int, int>

class _1584_min_cost_to_connect_all_points_prim
{
    int visited[1000];
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        memset(visited, 0, 1000 * 4);

        vector<vector<pair<int, int>>> edges(n);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges[i].push_back({ dis, j });
                edges[j].push_back({ dis, i });
            }

        // 第一步只加入第一個點關聯的 edge
        priority_queue<pii, vector<pii>, greater<pii>> pq(edges[0].begin(), edges[0].end());
        visited[0] = 1;
        int result = 0;

        for (int k = 0; k < n - 1; k++) {
            while (!pq.empty() && visited[pq.top().second] == 1)
                pq.pop();
            int next = pq.top().second;
            visited[next] = 1;
            result += pq.top().first;
            pq.pop();

            // 加入下一個點關聯的 edge
            for (auto edge : edges[next])
                pq.push(edge);
        }

        return result;
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
