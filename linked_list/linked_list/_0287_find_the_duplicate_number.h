#pragma once

#include <iostream>
#include <vector>
#include "define.h"

using namespace std;



class _0287_find_the_duplicate_number
{
public:
	int findDuplicate(vector<int>& nums) {
		int slow = nums[0];
		int fast = nums[nums[0]];

		while (slow != fast) {
			slow = nums[slow];
			fast = nums[nums[fast]];
		}

		slow = 0;
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
	}

	void do_test(_0287_find_the_duplicate_number* sol)
	{
		vector<int> nums1 = { 1, 3, 4, 2, 2 };
		int ret1 = sol->findDuplicate(nums1);
		cout << ret1 << endl;
		//Output : 2
		

		vector<int> nums2 = { 3, 1, 3, 4, 2 };
		int ret2 = sol->findDuplicate(nums2);
		cout << ret2 << endl;
		//Output : 3
	}
};
