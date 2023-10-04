#pragma once

#include <iostream>
#include <vector>

using namespace std;

class _0704_binary_search
{
public:
	int search(vector<int>& nums, int target) {
		int l = 0;
		int r = nums.size() - 1;
		// 總是使用 l <= r, 少了=會需要多考慮一些 edge case
		while (l <= r)
		{
			int m = l + (r - l + 1) / 2;
			if (nums[m] > target) {
				r = m - 1;
			}
			else if (nums[m] < target) {
				l = m + 1;
			}
			else
			{
				return m;
			}
		}
		return -1;
	}


	void do_test(_0704_binary_search* sol)
	{
		vector<int> nums1 = { -1, 0, 3, 5, 9, 12 };
		int target1 = 9;
		int ret1 = sol->search(nums1, target1);
		//Output : 4
		cout << ret1 << endl;

		vector<int> nums2 = { -1, 0, 3, 5, 9, 12 }; 
		int target2 = 2;
		int ret2 = sol->search(nums2, target2);
		//Output : -1
		cout << ret2 << endl;
	}
};






