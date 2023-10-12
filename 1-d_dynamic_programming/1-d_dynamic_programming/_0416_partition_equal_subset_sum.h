#pragma once

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


class _0416_partition_equal_subset_sum
{
public:
	bool canPartition(vector<int>& nums)
	{
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 != 0) return false;

		vector<bool>dp(sum / 2 + 1, 0);
		dp[0] = true;

		for (auto x : nums)
		{
			for (int s = sum / 2; s >= 1; s--)
			{
				if (s - x >= 0 && dp[s - x] == true)
					dp[s] = true;
			}
		}
		return dp[sum / 2];
	}

	// method2 - use unordered set
	/*
	bool canPartition(vector<int>& nums) {
		int target = 0;
		for (int i = 0; i < nums.size(); i++) {
			target += nums[i];
		}
		if (target % 2 != 0) {
			return false;
		}
		target /= 2;

		unordered_set<int> dp;
		dp.insert(0);

		for (int i = 0; i < nums.size(); i++) {
			unordered_set<int> dpNext;
			for (auto it = dp.begin(); it != dp.end(); it++) {
				if (*it + nums[i] == target) {
					return true;
				}
				dpNext.insert(*it + nums[i]);
				dpNext.insert(*it);
			}
			dp = dpNext;
		}

		return false;
	}
	*/

	void do_test(_0416_partition_equal_subset_sum* sol)
	{
		vector<int> nums1 = { 1, 5, 11, 5 };
		int ret1 = sol->canPartition(nums1);
		cout << ret1 << endl;
		//Output : true
		//Explanation : The array can be partitioned as[1, 5, 5] and [11].
		

		vector<int> nums2 = { 1, 2, 3, 5 };
		int ret2 = sol->canPartition(nums2);
		cout << ret2 << endl;
		//Output : false
		//Explanation : The array cannot be partitioned into equal sum subsets.
	}
};


