#pragma once

#include <iostream>
#include <vector>
#include <map>

using namespace std;


class _0494_target_sum
{
	map<pair<int, int>, int> dp;
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		return backtrack(nums, target, 0, 0);
	}

	int backtrack(vector<int>& nums, int target, int i, int total) {
		if (i == nums.size()) {
			return total == target ? 1 : 0;
		}
		if (dp.find({ i, total }) != dp.end()) {
			return dp[{i, total}];
		}

		dp[{i, total}] = backtrack(nums, target, i + 1, total + nums[i]) +
			backtrack(nums, target, i + 1, total - nums[i]);

		return dp[{i, total}];
	}

	void clean_map() {
		dp.clear();
	}

	void do_test(_0494_target_sum* sol) {
		vector<int> nums1 = { 1, 1, 1, 1, 1 };
		int target1 = 3;
		int ret1 = sol->findTargetSumWays(nums1, target1);
		cout << ret1 << endl;
		/*
		Output : 5
		Explanation : There are 5 ways to assign symbols to make the sum of nums be target 3.
		- 1 + 1 + 1 + 1 + 1 = 3
		+ 1 - 1 + 1 + 1 + 1 = 3
		+ 1 + 1 - 1 + 1 + 1 = 3
		+ 1 + 1 + 1 - 1 + 1 = 3
		+ 1 + 1 + 1 + 1 - 1 = 3
		*/

		sol->clean_map();

		vector<int> nums2 = { 1 };
		int target2 = 1;
		int ret2 = sol->findTargetSumWays(nums2, target2);
		cout << ret2 << endl;
		// Output : 1
	}
};
