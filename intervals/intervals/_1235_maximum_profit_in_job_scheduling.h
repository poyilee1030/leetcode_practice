#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class _1235_maximum_profit_in_job_scheduling
{
public:
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		int n = startTime.size();
		vector<vector<int>>jobs;
		for (int i = 0; i < n; i++) {
			jobs.push_back({ startTime[i], endTime[i], profit[i] });
		}
			
		sort(jobs.begin(), jobs.end());

		unordered_map<int, int> cache;

		return dfs(jobs, cache, 0);
	}

	int dfs(vector<vector<int>> &jobs, unordered_map<int, int> &cache, int i) {
		if (i == jobs.size()) {
			return 0;
		}

		if (cache.find(i) != cache.end()) {
			return cache[i];
		}

		// dont include
		int res = dfs(jobs, cache, i + 1);

		// include
		/*
		int j = i + 1;
		while (j < jobs.size()) {
			if (jobs[i][1] <= jobs[j][0])
				break;
			j += 1;
		}
		*/
		int j = binary_seach(jobs, jobs[i][1]);
		cout << "j = " << j << endl;
		cache[i] = res = max(res, jobs[i][2] + dfs(jobs, cache, j));
		return res;
	}

	int binary_seach(vector<vector<int>>& jobs, int target) {
		int left = 0;
		int right = jobs.size() - 1;
		
		while (left <= right) {
			int mid = int((left + right) / 2);
			if (jobs[mid][0] >= target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}


	void do_test(_1235_maximum_profit_in_job_scheduling* sol) {
		vector<int> startTime1 = {1, 2, 3, 3};
		vector<int> endTime1 = {3, 4, 5, 6};
		vector<int> profit1 = {50, 10, 40, 70};
		int ret1 = sol->jobScheduling(startTime1, endTime1, profit1);
		cout << ret1 << endl;
		// Output : 120
		// Explanation : The subset chosen is the first and fourth job.
		// Time range{1 - 3} + {3 - 6}, we get profit of 120 = 50 + 70.

		vector<int> startTime2 = {1, 2, 3, 4, 6};
		vector<int> endTime2 = {3, 5, 10, 6, 9};
		vector<int> profit2 = {20, 20, 100, 70, 60};
		int ret2 = sol->jobScheduling(startTime2, endTime2, profit2);
		cout << ret2 << endl;
		// Output : 150
		// Explanation : The subset chosen is the first, fourth and fifth job.
		// Profit obtained 150 = 20 + 70 + 60.

		vector<int> startTime3 = {1, 1, 1};
		vector<int> endTime3 = {2, 3, 4};
		vector<int> profit3 = {5, 6, 4};
		int ret3 = sol->jobScheduling(startTime3, endTime3, profit3);
		cout << ret3 << endl;
		// Output : 6
	}
};
