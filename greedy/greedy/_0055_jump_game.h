#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0055_jump_game
{
public:
	bool canJump(vector<int>& nums) {
		return false;
	}

	void do_test(_0055_jump_game* sol) {
		vector<int> nums1 = { 2, 3, 1, 1, 4 };
		bool ret1 = sol->canJump(nums1);
		cout << ret1 << endl;
		// Output : true
		// Explanation : Jump 1 step from index 0 to 1, then 3 steps to the last index.
		

		vector<int> nums2 = { 3, 2, 1, 0, 4 };
		bool ret2 = sol->canJump(nums2);
		cout << ret2 << endl;
		// Output : false
		// Explanation : You will always arrive at index 3 no matter what.
		// Its maximum jump length is 0, which makes it impossible to reach the last index.
	}
};
