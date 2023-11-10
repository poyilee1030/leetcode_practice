#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <queue>

using namespace std;


class _1743_restore_the_array_from_adjacent_pairs
{
public:
	unordered_map<int, vector<int>> graph;

	vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
		for (auto& edge : adjacentPairs) {
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}

		int root = 0;
		for (auto& pair : graph) {
			if (pair.second.size() == 1) {
				root = pair.first;
				break;
			}
		}

		vector<int> ans;
		dfs(root, INT_MAX, ans);
		return ans;
	}

	void dfs(int node, int prev, vector<int>& ans) {
		ans.push_back(node);
		for (int neighbor : graph[node]) {
			if (neighbor != prev) {
				dfs(neighbor, node, ans);
			}
		}
	}

	/* Time Limit Exceed !
	vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
		vector<int> result;
		if (adjacentPairs.size() == 1) {
			result.push_back(adjacentPairs[0][0]);
			result.push_back(adjacentPairs[0][1]);
			return result;
		}
		
		deque<int> path;
		path.push_back(adjacentPairs[0][0]);
		path.push_back(adjacentPairs[0][1]);

		queue<pair<int, int>> q;
		for (int i = 1; i < adjacentPairs.size(); i++) {
			q.push({ adjacentPairs[i][0], adjacentPairs[i][1] });
		}

		while (q.size() > 0) {

			pair<int, int> p = q.front();
			q.pop();
			if (p.first == path.front()) {
				path.push_front(p.second);
			}
			else if (p.second == path.front()) {
				path.push_front(p.first);
			}
			else if (p.first == path.back()) {
				path.push_back(p.second);
			}
			else if (p.second == path.back()) {
				path.push_back(p.first);
			}
			else {
				q.push(p);
			}
		}

		while (path.size() > 0) {
			result.push_back(path.front());
			path.pop_front();
		}

		return result;
	}
	*/

	void do_test(_1743_restore_the_array_from_adjacent_pairs* sol) {
		vector<vector<int>> adjacentPairs1 = { {2, 1}, {3, 4}, {3, 2} };
		vector<int> ret1 = sol->restoreArray(adjacentPairs1);
		print_res(ret1);
		/*
		Output : [1, 2, 3, 4]
		Explanation : This array has all its adjacent pairs in adjacentPairs.
		Notice that adjacentPairs[i] may not be in left - to - right order.
		*/

		sol->graph.clear();

		vector<vector<int>> adjacentPairs2 = { {4, -2}, {1, 4}, {-3, 1} };
		vector<int> ret2 = sol->restoreArray(adjacentPairs2);
		print_res(ret2);
		/*
		Output : [-2, 4, 1, -3]
		Explanation : There can be negative numbers.
		Another solution is[-3, 1, 4, -2], which would also be accepted.
		*/

		sol->graph.clear();

		vector<vector<int>> adjacentPairs3 = { {100000, -100000} };
		vector<int> ret3 = sol->restoreArray(adjacentPairs3);
		print_res(ret3);
		// Output : [100000, -100000]
	}

	void print_res(vector<int> res) {
		cout << "[";
		for (int i = 0; i < res.size(); i++) {
			cout << res[i];

			if (i < res.size() - 1) {
				cout << ",";
			}
		}
		cout << "]" << endl;
	}
};

