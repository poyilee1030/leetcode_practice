#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0033_search_in_rotated_sorted_array
{
public:
	int search(vector<int>& nums, int target) {

		int l = 0;
		int r = nums.size() - 1;
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (target == nums[m])
				return m;

			if (nums[l] <= nums[m])
			{
				// left part
				if (target > nums[m] || target < nums[l])
					l = m + 1;
				else
					r = m - 1;
			}
			else
			{
				//right part
				if (target < nums[m] || target > nums[r])
					r = m - 1;
				else
					l = m + 1;
			}
		}

		return -1;
	}

	void do_test(_0033_search_in_rotated_sorted_array* sol)
	{
		vector<int> nums1 = { 4, 5, 6, 7, 0, 1, 2 };
		int target1 = 0;
		int ret1 = sol->search(nums1, target1);
		//Output : 4
		cout << ret1 << endl;

		vector<int> nums2 = { 4, 5, 6, 7, 0, 1, 2 };
		int target2 = 3;
		int ret2 = sol->search(nums2, target2);
		//Output : -1
		cout << ret2 << endl;

		vector<int> nums3 = { 1 };
		int target3 = 0;
		int ret3 = sol->search(nums3, target3);
		//Output : -1
		cout << ret3 << endl;
	}
};



