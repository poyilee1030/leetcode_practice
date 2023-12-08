#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0045_jump_game_ii
{
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        int i = 0;
        while (i < n - 1) {
            if (i + nums[i] >= n - 1) {
                result++;
                break;
            }
            int maxIndex = i + 1;
            int maxValue = 0;
            for (int j = i + 1; j < i + 1 + nums[i]; j++) {
                if (j + nums[j] > maxValue) {
                    maxIndex = j;
                    maxValue = j + nums[j];
                }
            }
            i = maxIndex;
            result++;
        }

        return result;
    }
    
    /* Time Limit Exceed, 想加入 cache 但想不到好方法
    int jump(vector<int>& nums) {
        int res = dfs(nums, 0, 0);
        return res;
    }

    int dfs(vector<int>& nums, int cur, int count) {
        if (cur >= nums.size() - 1) {
            return count;
        }

        int mincnt = INT_MAX;
        int jump = nums[cur];
        for (int i = 1; i <= jump; i++) {
            int cnt = dfs(nums, cur + i, count + 1);
            if (cnt < mincnt) {
                mincnt = cnt;
            }
        }
        return mincnt;
    }
    */

	void do_test(_0045_jump_game_ii* sol) {
        vector<int> nums0 = { 1, 2, 1, 1, 1 };
        int ret0 = sol->jump(nums0);
        cout << ret0 << endl;
        // Output : 3

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

        vector<int> nums3 = { 2, 1 };
        int ret3 = sol->jump(nums3);
        cout << ret3 << endl;
        // Output : 1
	}
};
