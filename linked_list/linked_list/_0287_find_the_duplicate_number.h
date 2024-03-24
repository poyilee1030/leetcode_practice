#pragma once

#include <iostream>
#include <vector>
#include "define.h"

using namespace std;



class _0287_find_the_duplicate_number
{
public:

	/*
	int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        for (int i = 0; i <= n; i++) {
            while(i!=nums[i] && nums[i] < n && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            }
        }

        for (int i = 0; i <= n; i++) {
            if (i != nums[i])
                return nums[i];
        }
        return -1;
    }
	*/

	int findDuplicate(vector<int>& nums) {
		int slow = nums[0];
		int fast = nums[nums[0]];

		// 「一定」會在循環的前一個停下來
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[nums[fast]];
		}

		// 再用另一個變數從頭開始走，會在循環入口相遇
		int slow2 = 0;
		while (slow2 != fast) {
			slow2 = nums[slow2];
			fast = nums[fast];
		}
		return slow2;
	}

	void do_test(_0287_find_the_duplicate_number* sol)
	{
		int ret = -1;

		vector<int> nums1 = { 1, 3, 4, 2, 2 };
		ret = sol->findDuplicate(nums1);
		cout << ret << endl;
		//Output : 2

		vector<int> nums2 = { 3, 1, 3, 4, 2 };
		ret = sol->findDuplicate(nums2);
		cout << ret << endl;
		//Output : 3

		vector<int> nums3 = { 2, 5, 9, 6, 9, 3, 8, 9, 7, 1 };
		ret = sol->findDuplicate(nums3);
		cout << ret << endl;
		//Output : 9
	}
};
