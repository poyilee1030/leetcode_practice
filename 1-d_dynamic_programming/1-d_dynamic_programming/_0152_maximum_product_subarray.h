#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0152_maximum_product_subarray
{
public:
	int maxProduct(vector<int>& nums) {
		int res = nums[0];
		int curMin = 1, curMax = 1;

		for (int i = 0; i < nums.size(); i++)
		{
			int n = nums[i];

			int tmp = curMax * n;
			curMax = max(max(n * curMax, n * curMin), n);
			curMin = min(min(tmp, n * curMin), n);
			res = max(res, curMax);
		}

		return res;
	}

	void do_test(_0152_maximum_product_subarray* sol)
	{
		vector<int> nums1 = { 2, 3, -2, 4 };
		int ret1 = sol->maxProduct(nums1);
		cout << ret1 << endl;
		//Output : 6
		//Explanation : [2, 3] has the largest product 6.
		

		vector<int> nums2 = { -2, 0, -1 };
		int ret2 = sol->maxProduct(nums2);
		cout << ret2 << endl;
		//Output : 0
		//Explanation : The result cannot be 2, because[-2, -1] is not a subarray.
	}
};




