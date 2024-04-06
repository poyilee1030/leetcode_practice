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
            if (nums2.size() % 2 == 1) {
                // odd
                return nums2[mid_idx];
            }
            else {
                // even
                return (nums2[mid_idx] + nums2[mid_idx - 1]) / 2.0;
            }
        }

        int mid_idx = nums1.size() / 2;

        for (int i = 0; i < nums2.size(); i++) {
            bs(nums1, nums2[i], mid_idx);
        }

        if (nums1.size() % 2 == 1) {
            // odd
            return nums1[mid_idx];
        }
        else {
            // even
            return (nums1[mid_idx] + nums1[mid_idx - 1]) / 2.0;
        }
    }

    void bs(vector<int>& nums1, int target, int& mid_idx) {
        if (target <= nums1[0]) {
            nums1.insert(nums1.begin(), target);
            if (nums1.size() % 2 == 1) {
                // even -> odd
            }
            else {
                // odd -> even
                mid_idx--;
            }
        }
        else if (nums1.back() < target) {
            nums1.push_back(target);
            if (nums1.size() % 2 == 1) {
                // even -> odd
            }
            else {
                // odd -> even
                mid_idx++;
            }
        }
        else {
            // 1 3  t=2
            int n = nums1.size();
            int l = 0;
            int r = n - 1;
            while (l < r) {
                int m = r - (r - l) / 2;
                if (target < m) {
                    r = m - 1;
                }
                else {
                    l = m;
                }
            }

            int mid_value = nums1[mid_idx];
            nums1.insert(nums1.begin() + l, target);
            if (target < mid_value) {
                if (nums1.size() % 2 == 1) {
                    // even -> odd

                }
                else {
                    // odd -> even
                    // 1 2 3 4
                    mid_idx--;
                }
            }
            else {
                if (nums1.size() % 2 == 1) {
                    // even -> odd

                }
                else {
                    // odd -> even
                    mid_idx++;
                }
            }
        }
    }

	void do_test(_0004_median_of_two_sorted_arrays* sol) {
        vector<int> nums1, nums2;
        double ret;

        nums1 = { 1, 3 };
        nums2 = { 2 };
        //ret = sol->findMedianSortedArrays(nums1, nums2);
        //cout << ret << endl;

        nums1 = { 1, 2 };
        nums2 = { 3, 4 };
        //ret = sol->findMedianSortedArrays(nums1, nums2);
        //cout << ret << endl;

        nums1 = { 0, 0 };
        nums2 = { 0, 0 };
        ret = sol->findMedianSortedArrays(nums1, nums2);
        cout << ret << endl;
	}
};
