#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0004_median_of_two_sorted_arrays
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty()) {
            int mid_idx = nums2.size() / 2;
            if (nums2.size() % 2 == 1)
                return nums2[mid_idx];
            else
                return (nums2[mid_idx] + nums2[mid_idx - 1]) / 2.0;
        }

        for (int i = 0; i < nums2.size(); i++)
            bs(nums1, nums2[i]);

        int mid_idx = nums1.size() / 2;
        if (nums1.size() % 2 == 1)
            return nums1[mid_idx];
        else
            return (nums1[mid_idx] + nums1[mid_idx - 1]) / 2.0;
    }

    void bs(vector<int>& nums1, int target) {
        if (target <= nums1[0])
            nums1.insert(nums1.begin(), target);
        else if (nums1.back() < target)
            nums1.push_back(target);
        else {
            int l = 0;
            int r = nums1.size() - 1;
            while (l < r) {
                int m = l + (r - l) / 2;
                if (target > nums1[m])
                    l = m + 1;
                else
                    r = m;
            }
            nums1.insert(nums1.begin() + l, target);
        }
    }

	void do_test(_0004_median_of_two_sorted_arrays* sol) {
        vector<int> nums1, nums2;
        double ret = -1;

        nums1 = { 1, 3 };
        nums2 = { 2 };
        ret = sol->findMedianSortedArrays(nums1, nums2);
        cout << ret << endl;
        // Output: 2

        nums1 = { 1, 2 };
        nums2 = { 3, 4 };
        ret = sol->findMedianSortedArrays(nums1, nums2);
        cout << ret << endl;
        // Output: 2.5

        nums1 = { 0, 0 };
        nums2 = { 0, 0 };
        ret = sol->findMedianSortedArrays(nums1, nums2);
        cout << ret << endl;
        // Output: 0

        nums1 = { 0, 0, 0, 0, 0 };
        nums2 = { -1, 0, 0, 0, 0, 0, 1 };
        ret = sol->findMedianSortedArrays(nums1, nums2);
        cout << ret << endl;
        // Output: 0
	}
};
