#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class _0261_graph_valid_tree
{
public:
    // translate python version
	bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = edges[i];
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        return (dfs(adj, visited, 0, -1) && n == visited.size());
    }

    bool dfs(vector<vector<int>>& adj, unordered_set<int>& visited, int i, int prev) {
        if (visited.count(i)) {
            return false;
        }
        visited.insert(i);
        for (int j : adj[i])
        {
            if (j == prev)
                continue;
            if (!dfs(adj, visited, j, i))
                return false;
        }
        return true;
    }

    /*
    Graph of nodes, list of edges, determine if edges make valid tree
    Ex. n = 5, edges = [[0,1],[0,2],[0,3],[1,4]] -> true

    (1) For graph to be a valid tree, must have exactly n - 1 edges
    (2) If graph fully connected & has n - 1 edges, can't contain cycle

    Time: O(n)
    Space: O(n)
    */
    /*
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = edges[i];
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n);
        if (hasCycle(adj, visited, -1, 0)) {
            return false;
        }
        
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }

    bool hasCycle(vector<vector<int>>& adj, vector<bool>& visited, int parent, int child) {
        if (visited[child]) {
            return true;
        }
        visited[child] = true;
        // checking for cycles and connectedness
        for (int i = 0; i < adj[child].size(); i++) {
            int curr = adj[child][i];
            if (curr != parent && hasCycle(adj, visited, child, curr)) {
                return true;
            }
        }
        return false;
    }
    */

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
