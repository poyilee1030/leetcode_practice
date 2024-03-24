#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0300_longest_increasing_subsequence
{
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n, 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j])
					dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, dp[i]);
		}
		return ans;
	}
	/*
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n, 1);
		int result = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (nums[i] < nums[j]) 
				{
					dp[i] = max(dp[i], 1 + dp[j]);
				}
			}
			result = max(result, dp[i]);
		}
		return result;
	}
	*/

	void do_test(_0300_longest_increasing_subsequence* sol)
	{
		vector<int> nums1 = { 10, 9, 2, 5, 3, 7, 101, 18 };
		int ret1 = sol->lengthOfLIS(nums1);
		cout << ret1 << endl;
		//Output : 4
		//Explanation : The longest increasing subsequence is[2, 3, 7, 101], therefore the length is 4.


		vector<int> nums2 = { 0, 1, 0, 3, 2, 3 };
		int ret2 = sol->lengthOfLIS(nums2);
		cout << ret2 << endl;
		//Output : 4


		vector<int> nums3 = { 7, 7, 7, 7, 7, 7, 7 };
		int ret3 = sol->lengthOfLIS(nums3);
		cout << ret3 << endl;
		//Output : 1
	}
};
