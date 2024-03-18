#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0912_sort_an_array {
public:
    /* �ۤv�̪�ı�Q���A�Ĳv���t�A�]��L leetcode (610ms)
    vector<int> merge(vector<int>& pa, vector<int>& pb) {
        vector<int> ans;
        int i = 0;
        int j = 0;
        while (i < pa.size() && j < pb.size()) {
            if (pa[i] <= pb[j]) {
                ans.push_back(pa[i]);
                i++;
            }
            else {
                ans.push_back(pb[j]);
                j++;
            }
        }
        while (i < pa.size()) {
            ans.push_back(pa[i]);
            i++;
        }
        while (j < pb.size()) {
            ans.push_back(pb[j]);
            j++;
        }
        return ans;
    }

    vector<int> mergeSort(vector<int>& nums, int start, int end) {
        if (end - start + 1 == 1) {
            return { nums[start] };
        }
        else if (end - start + 1 == 2) {
            if (nums[start] < nums[end])
                return { nums[start], nums[end] };
            else
                return { nums[end], nums[start] };
        }
        else {
            int mid = (start + end) / 2;
            vector<int> part_a = mergeSort(nums, start, mid);
            vector<int> part_b = mergeSort(nums, mid + 1, end);
            return merge(part_a, part_b);
        }
    }
    */
    
    // leetcode (275 ms)
    void mergeSort(vector<int>& arr, int start, int end)
    {
        if (start < end)
        {
            int mid = start + (end - start) / 2;
            mergeSort(arr, start, mid);
            mergeSort(arr, mid + 1, end);
            merge(arr, start, mid, end);
        }
    }

    void merge(vector<int>& arr, int low, int mid, int high)
    {
        if (low >= high) return;

        int l = low, r = mid + 1, k = 0, size = high - low + 1;
        vector<int> sorted(size, 0);

        while (l <= mid && r <= high)
            sorted[k++] = arr[l] < arr[r] ? arr[l++] : arr[r++];

        while (l <= mid) sorted[k++] = arr[l++];
        while (r <= high) sorted[k++] = arr[r++];

        for (k = 0; k < size; k++)
            arr[k + low] = sorted[k];
    }

    vector<int> sortArray(vector<int>& nums) {
        //return mergeSort(nums, 0, nums.size() - 1);
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

	void do_test(_0912_sort_an_array* sol) {
        vector<int> nums1 = { 5, 2, 3, 1 };
        vector<int> ret1 = sol->sortArray(nums1);
        print_vector(ret1);
        // Output : [1, 2, 3, 5]
        
        vector<int> nums2 = { 5, 1, 1, 2, 0, 0 };
        vector<int> ret2 = sol->sortArray(nums2);
        print_vector(ret2);
        // Output : [0, 0, 1, 1, 2, 5]
	}

    template <typename T>
    void print_vector(vector<T> v) {
        cout << "[";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i < v.size() - 1) {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
};




