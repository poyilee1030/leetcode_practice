#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class _0332_reconstruct_itinerary
{
public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		vector<string> a = { "a" };
		return a;
	}

	void do_test(_0332_reconstruct_itinerary* sol)
	{
		vector<vector<string>> tickets1 = { {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"} };
		vector<string> ret1 = sol->findItinerary(tickets1);
		print_res(ret1);
		// Output : ["JFK", "MUC", "LHR", "SFO", "SJC"]

		vector<vector<string>> tickets2 = { {"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"} };
		vector<string> ret2 = sol->findItinerary(tickets2);
		print_res(ret2);
		// Output : ["JFK", "ATL", "JFK", "SFO", "ATL", "SFO"]
		// Explanation : Another possible reconstruction is["JFK", "SFO", "ATL", "JFK", "ATL", "SFO"] 
		// but it is larger in lexical order.
	}

	void print_res(vector<string>& result)
	{
		cout << "[";
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i];
			if (i < result.size() - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}
};

