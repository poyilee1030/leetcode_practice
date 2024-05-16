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
		vector<int> nums;
		int ret;
		
		nums = { -1, 0, 3, 5, 9, 12 };
		ret = sol->search(nums, 9);
		//Output : 4
		cout << ret << endl;

		nums = { -1, 0, 3, 5, 9, 12 }; 
		ret = sol->search(nums, 2);
		//Output : -1
		cout << ret << endl;
	}
};
