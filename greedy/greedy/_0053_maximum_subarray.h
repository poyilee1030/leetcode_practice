#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
	Given int array, find contiguous subarray w/ max sum
	Ex. nums = [-2,1,-3,4,-1,2,1,-5,4] -> 6, [4,-1,2,1]

	At each point, determine if it's better to add to curr sum or start over

	Time: O(n)
	Space: O(1)
*/

class _0053_maximum_subarray
{
public:
	int maxSubArray(vector<int>& nums) {
		int res = nums[0];

		int total = 0;
		for (int i = 0; i < nums.size(); i++) {
			total += nums[i];
			res = max(res, total);
			if (total < 0)
				total = 0;
		}

		return res;
	}

	void do_test(_0053_maximum_subarray* sol) {
		vector<int> nums1 = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
		int ret1 = sol->maxSubArray(nums1);
		cout << ret1 << endl;
		// Output : 6
		// Explanation : The subarray[4, -1, 2, 1] has the largest sum 6.
		
		vector<int> nums2 = { 1 };
		int ret2 = sol->maxSubArray(nums2);
		cout << ret2 << endl;
		// Output : 1
		// Explanation : The subarray[1] has the largest sum 1.
		
		vector<int> nums3 = { 5, 4, -1, 7, 8 };
		int ret3 = sol->maxSubArray(nums3);
		cout << ret3 << endl;
		// Output : 23
		// Explanation : The subarray[5, 4, -1, 7, 8] has the largest sum 23.
	}
};
