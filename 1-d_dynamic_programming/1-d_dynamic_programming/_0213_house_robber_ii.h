#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0213_house_robber_ii
{
public:
	int rob(vector<int>& nums) {
		int n = nums.size();

		if (n == 1) {
			return nums[0];
		}

		int range1 = helper(nums, 0, n - 2);
		int range2 = helper(nums, 1, n - 1);

		return max(range1, range2);
	}

	int helper(vector<int>& nums, int start, int end) {
		int rob1 = 0;
		int	rob2 = 0;

		for (int i = start; i <= end; ++i)
		{
			int newRob = max(nums[i] + rob1, rob2);
			rob1 = rob2;
			rob2 = newRob;
		}

		return rob2;
	}

	void do_test(_0213_house_robber_ii* sol)
	{
		vector<int> nums1 = { 2, 3, 2 };
		int ret1 = sol->rob(nums1);
		cout << ret1 << endl;
		/*
		Output: 3
		Explanation : You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), 
		because they are adjacent houses.
		*/
		
		vector<int> nums2 = { 1, 2, 3, 1 };
		int ret2 = sol->rob(nums2);
		cout << ret2 << endl;
		/*
		Output : 4
		Explanation : Rob house 1 (money = 1) and then rob house 3 (money = 3).
		Total amount you can rob = 1 + 3 = 4.
		*/
		
		vector<int> nums3 = { 1, 2, 3 };
		int ret3 = sol->rob(nums3);
		cout << ret3 << endl;
		// Output : 3
	}
};





