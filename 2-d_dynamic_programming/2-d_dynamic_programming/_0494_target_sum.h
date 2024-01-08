#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class _0494_target_sum
{
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		return 0;
	}

	void do_test(_0494_target_sum *sol) {
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

		vector<int> nums2 = { 1 };
		int target2 = 1;
		int ret2 = sol->findTargetSumWays(nums2, target2);
		cout << ret2 << endl;
		// Output : 1
	}
};