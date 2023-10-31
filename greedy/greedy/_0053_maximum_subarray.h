#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0053_maximum_subarray
{
public:
	int maxSubArray(vector<int>& nums) {
		return 0;
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
