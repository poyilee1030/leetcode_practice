#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0912_sort_an_array_quick_sort {
public:

    vector<int> sortArray(vector<int>& nums) {
        return nums;
    }

	void do_test(_0912_sort_an_array_quick_sort* sol) {
        vector<int> nums = { 5, 2, 3, 1 };
        vector<int> ret;

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
