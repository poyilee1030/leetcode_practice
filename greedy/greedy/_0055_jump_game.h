#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0055_jump_game
{
public:
	bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reachable = 0;

        for (int i = 0; i < n; i++) {
            if (i > reachable) {
                return false;
            }
            reachable = max(reachable, i + nums[i]);
            if (reachable >= n - 1) {
                break;
            }
        }

        return true;
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

        vector<int> nums3 = { 2, 0 };
        bool ret3 = sol->canJump(nums3);
        cout << ret3 << endl;
        // Output : true

        vector<int> nums4 = { 1, 1, 1, 0 };
        bool ret4 = sol->canJump(nums4);
        cout << ret4 << endl;
        // Output : true
	}
};
