#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
	Given array of non-overlapping intervals & a new interval, insert & merge if necessary
	Ex. intervals = [[1,3],[6,9]], newInterval = [2,5] -> [[1,5],[6,9]]

	To merge: while intervals are still overlapping the new one, take the larger bounds

	Time: O(n)
	Space: O(n)
*/

class _0057_insert_interval
{
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> ans;
		int newStart = newInterval[0];
		int newEnd = newInterval[1];
		int n = intervals.size();
		for (int i = 0; i < n; i++) {
			// Case 1: Non overlapping interval
			// If new interval is before the current interval
			if (intervals[i][0] > newEnd) {
				ans.push_back(newInterval);
				copy(intervals.begin() + i, intervals.end(), back_inserter(ans));
				return ans;
			}
			// If new interval is after the current interval
			else if (intervals[i][1] < newStart) {
				ans.push_back(intervals[i]);
			}
			// Case 2: Overlapping interval
			else {
				newInterval[0] = min(newInterval[0], intervals[i][0]);
				newInterval[1] = max(newInterval[1], intervals[i][1]);
			}
		}
		ans.push_back(newInterval);
		return ans;
	}

	void do_test(_0057_insert_interval* sol) {
		vector<vector<int>> intervals1 = { {1, 3}, {6, 9} };
		vector<int> newInterval1 = { 2, 5 };
		vector<vector<int>> ret1 = sol->insert(intervals1, newInterval1);
		print_res(ret1);
		// Output : {{1, 5}, {6, 9}}

		vector<vector<int>> intervals2 = { {1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16} };
		vector<int> newInterval2 = { 4, 8 };
		vector<vector<int>> ret2 = sol->insert(intervals2, newInterval2);
		print_res(ret2);
		// Output : {{1, 2}, {3, 10}, {12, 16}}
		// Explanation : Because the new interval[4, 8] overlaps with[3, 5}, {6, 7}, {8, 10].
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
