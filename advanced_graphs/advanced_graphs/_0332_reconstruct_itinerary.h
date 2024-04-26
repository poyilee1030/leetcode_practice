#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include "utils.h"

using namespace std;


class _0332_reconstruct_itinerary
{
    unordered_map<string, queue<string>> route;
public:
    vector<string> findItinerary(vector<vector<string>> tickets)
    {
        sort(tickets.begin(), tickets.end());
        for (auto ticket: tickets)
            route[ticket[0]].push(ticket[1]);

        vector<string> path;
        dfs("JFK", path);
        reverse(path.begin(), path.end());
        return path;
    }

    void dfs(string start, vector<string>& path) {
        while (route[start].size() > 0) {
            string nextStart = route[start].front();
            route[start].pop();
            dfs(nextStart, path);
        }
        path.push_back(start);
    }

	void do_test(_0332_reconstruct_itinerary* sol)
	{
		vector<vector<string>> tickets;
		vector<string> ret;

		tickets = { {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"} };
		ret = sol->findItinerary(tickets);
		print_vector(ret);
		// Output : ["JFK", "MUC", "LHR", "SFO", "SJC"]

		tickets = { {"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"} };
		ret = sol->findItinerary(tickets);
		print_vector(ret);
		// Output : ["JFK", "ATL", "JFK", "SFO", "ATL", "SFO"]
		// Explanation : Another possible reconstruction is["JFK", "SFO", "ATL", "JFK", "ATL", "SFO"] 
		// but it is larger in lexical order.
	}
};
