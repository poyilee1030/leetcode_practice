#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0198_house_robber
{
public:
	int rob(vector<int>& nums) {

	}

	void do_test(_0198_house_robber* sol)
	{
		vector<int> nums1 = { 1, 2, 3, 1 };
		int ret1 = sol->rob(nums1);
		cout << ret1 << endl;
		/*
		Output : 4
		Explanation : Rob house 1 (money = 1) and then rob house 3 (money = 3).
		Total amount you can rob = 1 + 3 = 4.
		*/

		vector<int> nums2 = { 2, 7, 9, 3, 1 };
		int ret2 = sol->rob(nums2);
		cout << ret2 << endl;
		/*
		Output : 12
		Explanation : Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
		Total amount you can rob = 2 + 9 + 1 = 12.
		*/
	}
};
