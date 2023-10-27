#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0136_single_number
{
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (int n : nums) {
			result = result ^ n;
		}
		return result;
	}

	void do_test(_0136_single_number* sol)
	{
		vector<int> nums1 = { 2, 2, 1 };
		int ret1 = sol->singleNumber(nums1);
		cout << ret1 << endl;
		// Output : 1


		vector<int> nums2 = { 4, 1, 2, 1, 2 };
		int ret2 = sol->singleNumber(nums2);
		cout << ret2 << endl;
		// Output : 4


		vector<int> nums3 = { 1 };
		int ret3 = sol->singleNumber(nums3);
		cout << ret3 << endl;
		// Output : 1
	}
};
