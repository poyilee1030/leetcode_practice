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
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != val)
            {
                swap(nums[i], nums[count]);
                count++;
            }
        }
        return count;
    }

	void do_test(_0027_remove_element* sol) {
        vector<int> nums1 = { 3, 2, 2, 3 }; 
        int val1 = 3;
        int ret1 = sol->removeElement(nums1, val1);
        cout << ret1 << endl;
        /*
        Output : 2, nums = [2, 2, _, _]
        Explanation : Your function should return k = 2, with the first two elements of nums being 2.
        It does not matter what you leave beyond the returned k(hence they are underscores).
        */
        
        vector<int> nums2 = { 0, 1, 2, 2, 3, 0, 4, 2 };
        int val2 = 2;
        int ret2 = sol->removeElement(nums2, val2);
        cout << ret2 << endl;
        /*
        Output : 5, nums = [0, 1, 4, 0, 3, _, _, _]
        Explanation : Your function should return k = 5, 
        with the first five elements of nums containing 0, 0, 1, 3, and 4.
        Note that the five elements can be returned in any order.
        It does not matter what you leave beyond the returned k(hence they are underscores).
        */

        vector<int> nums3 = { 1 };
        int val3 = 1;
        int ret3 = sol->removeElement(nums3, val3);
        cout << ret3 << endl;
        // Output : 0

        vector<int> nums4 = { 3, 3 };
        int val4 = 3;
        int ret4 = sol->removeElement(nums4, val4);
        cout << ret4 << endl;
        // Output : 0

        vector<int> nums5 = { 2 };
        int val5 = 3;
        int ret5 = sol->removeElement(nums5, val5);
        cout << ret5 << endl;
        // Output : 1

        vector<int> nums6 = { 3, 3 };
        int val6 = 5;
        int ret6 = sol->removeElement(nums6, val6);
        cout << ret6 << endl;
        // Output : 2
	}
};
