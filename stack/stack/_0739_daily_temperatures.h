#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	Given array of temps, return an array w/ # of days until warmer
	Ex. temperature = [73,74,75,71,69,72,76,73] -> [1,1,4,2,1,1,0,0]

	Monotonic decr stack, at each day, compare incr from prev days

	Time: O(n)
	Space: O(n)
*/

class _0739_daily_temperatures
{
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		int n = temperatures.size();

		// pair: [index, temp]
		stack<pair<int, int>> stk;
		vector<int> result(n);

		for (int i = 0; i < n; i++) {
			int currDay = i;
			int currTemp = temperatures[i];

			while (!stk.empty() && stk.top().second < currTemp) {
				int prevDay = stk.top().first;
				int prevTemp = stk.top().second;
				stk.pop();

				result[prevDay] = currDay - prevDay;
			}

			stk.push({ currDay, currTemp });
		}

		return result;
	}

	void do_test(_0739_daily_temperatures* sol)
	{
		vector<int> temperatures1 = { 73, 74, 75, 71, 69, 72, 76, 73 };
		vector<int> res1 = sol->dailyTemperatures(temperatures1);
		print_res(res1);
		//Output : [1, 1, 4, 2, 1, 1, 0, 0]
		
		vector<int> temperatures2 = { 30, 40, 50, 60 };
		vector<int> res2 = sol->dailyTemperatures(temperatures2);
		print_res(res2);
		//Output : [1, 1, 1, 0]
		
		vector<int> temperatures3 = { 30, 60, 90 };
		vector<int> res3 = sol->dailyTemperatures(temperatures3);
		print_res(res3);
		//Output : [1, 1, 0]
	}

	void print_res(vector<int>& res)
	{
		cout << "[";
		for (unsigned int i = 0; i < res.size(); ++i)
		{
			cout << res[i] << ",";
		}
		cout << "]" << endl;
	}
};



