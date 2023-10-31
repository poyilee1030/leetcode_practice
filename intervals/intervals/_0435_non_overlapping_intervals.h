#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class _0435_non_overlapping_intervals
{
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		int n = intervals.size();
		if (n == 1) {
			return 0;
		}

		sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
			return a[0] < b[0];
			});

		int result = 0;
		int lastEnd = intervals[0][1];
		for (int i = 1; i < intervals.size(); i++) {
			int start = intervals[i][0];
			int end = intervals[i][1];
			if (start >= lastEnd) {
				lastEnd = end;
			}
			else {
				result += 1;
				lastEnd = min(end, lastEnd);
			}
		}
		return result;
	}

	void do_test(_0435_non_overlapping_intervals* sol) {
		vector<vector<int>> intervals1 = { {1, 2}, {2, 3}, {3, 4}, {1, 3} };
		int ret1 = sol->eraseOverlapIntervals(intervals1);
		cout << ret1 << endl;
		// Output : 1
		// Explanation : [1, 3] can be removed and the rest of the intervals are non - overlapping.
		

		vector<vector<int>> intervals2 = { {1, 2}, {1, 2}, {1, 2} };
		int ret2 = sol->eraseOverlapIntervals(intervals2);
		cout << ret2 << endl;
		// Output : 2
		// Explanation : You need to remove two[1, 2] to make the rest of the intervals non - overlapping.
		

		vector<vector<int>> intervals3 = { {1, 2}, {2, 3} };
		int ret3 = sol->eraseOverlapIntervals(intervals3);
		cout << ret3 << endl;
		// Output : 0
		// Explanation : You don't need to remove any of the intervals since they're already non - overlapping.
	}
};
