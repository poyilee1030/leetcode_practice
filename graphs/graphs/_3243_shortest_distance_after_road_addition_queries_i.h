#pragma once

using pii = pair<int, int>;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


class _3243_shortest_distance_after_road_addition_queries_i
{
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries)
    {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        vector<int> dist;
        for (int i = 0; i < n; i++) {
            dist.push_back(i);
        }

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            vector<int>& qi = queries[i];
            int src = qi[0];
            int dest = qi[1];
            adj[src].push_back(dest);
            ans[i] = bfs(n, adj, dist, src, dest);
        }
        return ans;
    }

    int bfs(int n, vector<vector<int>> adj, vector<int>& dist, int src, int dest) {
        if (dist[src] + 1 < dist[dest]) {
            queue<int> q;
            q.push(dest);
            dist[dest] = dist[src] + 1;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (auto& next : adj[v]) {
                    if (dist[v] + 1 < dist[next]) {
                        dist[next] = dist[v] + 1;
                        q.push(next);
                    }
                }
            }
        }
        return dist[n - 1];
    }

    void do_test(_3243_shortest_distance_after_road_addition_queries_i* sol)
    {
        vector<vector<int>> edges;
        vector<int> ret;

        edges = { {2, 4}, {0, 2}, {0, 4} };
        ret = sol->shortestDistanceAfterQueries(5, edges);
        print_vector(ret);
        // Output : [2, 3]

        edges = { {0, 3}, {0, 2} };
        ret = sol->shortestDistanceAfterQueries(4, edges);
        print_vector(ret);
        // Output : [2, 3]
        
        edges = { {0, 2}, {0, 3} };
        ret = sol->shortestDistanceAfterQueries(6, edges);
        print_vector(ret);
        // Output : [4, 3]
    }
};
