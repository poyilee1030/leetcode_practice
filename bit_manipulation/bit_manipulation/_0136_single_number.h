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
		vector<int> nums;
		int ret;

		nums = { 2, 2, 1 };
		ret = sol->singleNumber(nums);
		cout << ret << endl;
		// Output : 1

		nums = { 4, 1, 2, 1, 2 };
		ret = sol->singleNumber(nums);
		cout << ret << endl;
		// Output : 4

		nums = { 1 };
		ret = sol->singleNumber(nums);
		cout << ret << endl;
		// Output : 1
	}
};
