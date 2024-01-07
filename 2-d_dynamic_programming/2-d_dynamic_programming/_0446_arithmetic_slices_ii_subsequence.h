#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;


class _0446_arithmetic_slices_ii_subsequence
{
public:
	int numberOfArithmeticSlices(vector<int>& nums) {
		int n = nums.size();
		//unordered_map<long, int> dp[n];
		vector<unordered_map<long, int>> dp(n);
		int result = 0;

		for (int i = 1; i < nums.size(); i++) {
			for (int j = i - 1; j >= 0; j--) {
				long diff = (long)nums[i] - (long)nums[j];
				dp[i][diff] += dp[j][diff] + 1;
				result += dp[j][diff];
			}
		}

		return result;
	}

	//1, 3, 5, 7, 9

	void do_test(_0446_arithmetic_slices_ii_subsequence* sol) {
		vector<int> nums1 = { 2, 4, 6, 8, 10 };
		int ret1 = sol->numberOfArithmeticSlices(nums1);
		cout << ret1 << endl;
		/*
		Output : 7
		Explanation : All arithmetic subsequence slices are :
		[2, 4, 6]
		[4, 6, 8]
		[6, 8, 10]
		[2, 4, 6, 8]
		[4, 6, 8, 10]
		[2, 4, 6, 8, 10]
		[2, 6, 10]
		*/
		
		vector<int> nums2 = { 7, 7, 7, 7, 7 };
		int ret2 = sol->numberOfArithmeticSlices(nums2);
		cout << ret2 << endl;
		// Output: 16

		
		vector<int> nums3 = { 0, 2000000000, -294967296 };
		int ret3 = sol->numberOfArithmeticSlices(nums3);
		cout << ret3 << endl;
		// Output: 1
	}
};





