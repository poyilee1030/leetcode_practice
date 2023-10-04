#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


class _0215_kth_largest_element_in_an_array
{
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }

    int quickSelect(vector<int>& nums, int k) {
        int pivot = nums[rand() % nums.size()];

        vector<int> left;
        vector<int> mid;
        vector<int> right;

        for (int num : nums) {
            if (num > pivot) {
                right.push_back(num);
            }
            else if (num < pivot) {
                left.push_back(num);
            }
            else {
                mid.push_back(num);
            }
        }

        if (k <= right.size()) {
            return quickSelect(right, k);
        }

        if (right.size() + mid.size() < k) {
            return quickSelect(left, k - right.size() - mid.size());
        }

        return pivot;
    }

	void do_test(_0215_kth_largest_element_in_an_array* sol)
	{
		vector<int> nums1 = { 3, 2, 1, 5, 6, 4 };
		int k1 = 2;
		int res1 = findKthLargest(nums1, k1);
		cout << res1 << endl;
		//Output : 5
		

		vector<int> nums2 = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
		int k2 = 4;
		int res2 = findKthLargest(nums2, k2);
		cout << res2 << endl;
		//Output : 4
	}
};




