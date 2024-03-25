#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0027_remove_element
{
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                swap(nums[i], nums[count]);
                count++;
            }
        }
        return count;
    }

	void do_test(_0027_remove_element* sol) {
        vector<int> nums;
        int ret;
        
        nums = { 3, 2, 2, 3 };
        ret = sol->removeElement(nums, 3);
        cout << ret << endl;
        /*
        Output : 2, nums = [2, 2, _, _]
        Explanation : Your function should return k = 2, with the first two elements of nums being 2.
        It does not matter what you leave beyond the returned k(hence they are underscores).
        */
        
        nums = { 0, 1, 2, 2, 3, 0, 4, 2 };
        ret = sol->removeElement(nums, 2);
        cout << ret << endl;
        /*
        Output : 5, nums = [0, 1, 4, 0, 3, _, _, _]
        Explanation : Your function should return k = 5, 
        with the first five elements of nums containing 0, 0, 1, 3, and 4.
        Note that the five elements can be returned in any order.
        It does not matter what you leave beyond the returned k(hence they are underscores).
        */

        nums = { 1 };
        ret = sol->removeElement(nums, 1);
        cout << ret << endl;
        // Output : 0

        nums = { 3, 3 };
        ret = sol->removeElement(nums, 3);
        cout << ret << endl;
        // Output : 0

        nums = { 2 };
        ret = sol->removeElement(nums, 3);
        cout << ret << endl;
        // Output : 1

        nums = { 3, 3 };
        ret = sol->removeElement(nums, 5);
        cout << ret << endl;
        // Output : 2
	}
};
