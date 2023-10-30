#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	Given an array of intervals, merge all overlapping intervals
	Ex. intervals = [[1,3],[2,6],[8,10],[15,18]] -> [[1,6],[8,10],[15,18]]

	Sort by earliest start time, merge overlapping intervals (take longer end time)

	Time: O(n log n)
	Space: O(n)
*/

class _0056_merge_intervals
{
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int n = intervals.size();
		if (n == 1) {
			return intervals;
		}

		sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
			return a[0] < b[0];
			});

		vector<vector<int>> output = { intervals[0] };

		for (int i = 1; i < intervals.size(); i++) {
			int lastEnd = output[output.size() - 1][1];

			int start = intervals[i][0];
			int end = intervals[i][1];
			if (start <= lastEnd)
				output[output.size() - 1][1] = max(lastEnd, end);
			else
				output.push_back({ start, end });
		}

		return output;
	}

	void do_test(_0056_merge_intervals* sol) {
		vector<vector<int>> intervals1 = { {1, 3}, {2, 6}, {8, 10}, {15, 18} };
		vector<vector<int>> ret1 = sol->merge(intervals1);
		print_res(ret1);
		// Output : {{1, 6}, {8, 10}, {15, 18}}
		// Explanation : Since intervals[1, 3] and [2, 6] overlap, merge them into[1, 6].
		
		vector<vector<int>> intervals2 = { {1, 4}, {4, 5} };
		vector<vector<int>> ret2 = sol->merge(intervals2);
		print_res(ret2);
		// Output : {{1, 5}}
		// Explanation : Intervals[1, 4] and [4, 5] are considered overlapping.
	}

	void print_res(vector<vector<int>>& res) {
		cout << "[";
		for (int i = 0; i < res.size(); i++) {
			cout << "[";
			vector<int> oo = res[i];
			for (int j = 0; j < oo.size(); j++) {
				cout << oo[j];
				if (j < oo.size() - 1)
					cout << ",";
			}
			cout << "]";
			if (i < res.size() - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}
};
