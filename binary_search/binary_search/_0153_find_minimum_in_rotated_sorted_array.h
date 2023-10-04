#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0153_find_minimum_in_rotated_sorted_array
{
public:
	int findMin(vector<int>& nums) {
		int res = nums[0];
		int l = 0;
		int r = nums.size() - 1;

		while (l <= r)
		{
			if (nums[l] < nums[r])
			{
				res = min(res, nums[l]);
				break;
			}
			int m = (l + r) / 2;
			res = min(res, nums[m]);
			if (nums[m] >= nums[l])
			{
				l = m + 1;
			}
			else
			{
				r = m - 1;
			}
		}
		return res;
	}

	void do_test(_0153_find_minimum_in_rotated_sorted_array* sol)
	{
		vector<int> nums1 = { 3, 4, 5, 1, 2 };
		int ret1 = sol->findMin(nums1);
		cout << ret1 << endl;
		//Output : 1
		//Explanation : The original array was{1, 2, 3, 4, 5} rotated 3 times.
		

		vector<int> nums2 = { 4, 5, 6, 7, 0, 1, 2 };
		int ret2 = sol->findMin(nums2);
		cout << ret2 << endl;
		//Output : 0
		//Explanation : The original array was{0, 1, 2, 4, 5, 6, 7} and it was rotated 4 times.
		

		vector<int> nums3 = { 11, 13, 15, 17 };
		int ret3 = sol->findMin(nums3);
		cout << ret3 << endl;
		//Output : 11
		//Explanation : The original array was{11, 13, 15, 17} and it was rotated 4 times.
	}
};

