#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _1470_shuffle_the_array
{
public:
	vector<int> shuffle(vector<int>& nums, int n) {
		vector<int> q;
		return q;
	}

	void do_test(_1470_shuffle_the_array* sol) {
		vector<int> nums1 = { 2, 5, 1, 3, 4, 7 };
		vector<int> ret1 = sol->shuffle(nums1, 3);
		print_res(ret1);
		// Output : [2, 3, 5, 4, 1, 7]
		// Explanation : Since x1 = 2, x2 = 5, x3 = 1, y1 = 3, y2 = 4, y3 = 7 
		// then the answer is[2, 3, 5, 4, 1, 7].
		
		vector<int> nums2 = { 1, 2, 3, 4, 4, 3, 2, 1 };
		vector<int> ret2 = sol->shuffle(nums2, 4);
		print_res(ret2);
		// Output : [1, 4, 2, 3, 3, 2, 4, 1]
		
		vector<int> nums3 = { 1, 1, 2, 2 };
		vector<int> ret3 = sol->shuffle(nums3, 2);
		print_res(ret3);
		// Output : [1, 2, 1, 2]
	}

	void print_res(vector<int>& res) {
		cout << "[";
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i];
			if (i < res.size() - 1)
				cout << ",";
		}
		cout << "]";
	}
};


