#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0912_sort_an_array_quick_sort {
public:
    /*
    int partition(vector<int>& arr, int low, int high) {
        // 總是用第一個當 pivot, 在 leetcode 912 會 TLE
        int pivot_value = arr[low];
        int idx = high;
        for (int j = high; j > low; j--) {
            if (arr[j] > pivot_value) {
                swap(arr[idx], arr[j]);
                idx--;
            }
        }
        swap(arr[idx], arr[low]);
        return idx;
    }
    */
    
    // 總是用最後一個當 pivot, 在 leetcode 912 會 TLE
    int partition(vector<int>& arr, int low, int high) {
        int pivot_value = arr[high];
        int idx = low;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot_value) {
                swap(arr[idx], arr[j]);
                idx++;
            }
        }
        swap(arr[idx], arr[high]);
        return idx;
    }

    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            //smaller element than pivot goes left and higher element goes right
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

	void do_test(_0912_sort_an_array_quick_sort* sol) {
        vector<int> nums;
        vector<int> ret;

        nums = { 9, 4, 1, 6, 7, 3, 8, 2, 5 };
        ret = sol->sortArray(nums);
        print_vector(ret);
        // Output : [1, 2, 3, 4, 5, 6, 7, 8, 9]

        nums = { 5, 2, 3, 1 };
        ret = sol->sortArray(nums);
        print_vector(ret);
        // Output : [1, 2, 3, 5]

        nums = { 5, 1, 1, 2, 0, 0 };
        ret = sol->sortArray(nums);
        print_vector(ret);
        // Output : [0, 0, 1, 1, 2, 5]
	}
};
