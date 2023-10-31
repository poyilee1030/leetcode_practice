#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0045_jump_game_ii
{
public:
	int jump(vector<int>& nums) {
		return 0;
	}

	void do_test(_0045_jump_game_ii* sol) {
		vector<int> nums1 = { 2, 3, 1, 1, 4 };
		int ret1 = sol->jump(nums1);
		cout << ret1 << endl;
		// Output : 2
		// Explanation : The minimum number of jumps to reach the last index is 2.
		// Jump 1 step from index 0 to 1, then 3 steps to the last index.
		

		vector<int> nums2 = { 2, 3, 0, 1, 4 };
		int ret2 = sol->jump(nums2);
		cout << ret2 << endl;
		// Output : 2
	}
};