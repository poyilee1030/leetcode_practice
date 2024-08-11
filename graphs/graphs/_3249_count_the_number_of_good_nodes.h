#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;


class _3249_count_the_number_of_good_nodes
{
public:
    
    int countGoodNodes(vector<vector<int>>& edges) {
        int ans = 0;

        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < edges.size(); i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        unordered_set<int> visited;
        dfs(adj, 0, visited, ans);
        return ans;
    }

    int dfs(unordered_map<int, vector<int>>& adj, int start, unordered_set<int>& visited, int& ans) {
        vector<int> path = adj[start];
        if (path.size() == 0) {
            ans++;
            return 1;
        }

        visited.insert(start);

        int prev_count = -1;
        int total = 0;
        bool valid = true;

        for (int i = 0; i < path.size(); i++) {
            if (visited.find(path[i]) != visited.end())
                continue;
            
            int curr_count = dfs(adj, path[i], visited, ans);
            
            if (prev_count == -1)
                prev_count = curr_count;
            if (prev_count != curr_count)
                valid = false;
            total += curr_count;
        }

        if (valid)
            ans++;

        return total + 1;
    }

    void do_test(_3249_count_the_number_of_good_nodes* sol)
    {
        vector<vector<int>> edges;
        int ret;

        edges = { {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6} };
        ret = sol->countGoodNodes(edges);
        cout << ret << endl;
        // Output : 7

        edges = { {0, 1}, {1, 2}, {2, 3}, {3, 4}, {0, 5}, {1, 6}, {2, 7}, {3, 8} };
        ret = sol->countGoodNodes(edges);
        cout << ret << endl;
        // Output : 6

        edges = { {0, 1}, {1, 2}, {1, 3}, {1, 4}, {0, 5}, {5, 6}, {6, 7}, {7, 8}, {0, 9}, {9, 10}, {9, 12}, {10, 11} };
        ret = sol->countGoodNodes(edges);
        cout << ret << endl;
        // Output : 12

        edges = { {6, 0}, {1, 0}, {5, 1}, {2, 5}, {3, 1}, {4, 3} };
        ret = sol->countGoodNodes(edges);
        cout << ret << endl;
        // Output : 6
    }
};
