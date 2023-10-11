#pragma once

#include <iostream>
#include <vector>

using namespace std;

class _0239_sliding_window_maximum
{
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {

	}

	void do_test(_0239_sliding_window_maximum* sol)
	{
		vector<int> nums1 = { 1, 3, -1, -3, 5, 3, 6, 7 };
		int k1 = 3;
		vector<int> ret1 = sol->maxSlidingWindow(nums1, k1);
		print_res(ret1);
		//Output : [3, 3, 5, 5, 6, 7]
		//Explanation :
		//Window position                Max
		//-------------- - ---- -
		//[1  3  -1] -3  5  3  6  7       3
		// 1 [3  -1  -3] 5  3  6  7       3
		// 1  3 [-1  -3  5] 3  6  7       5
		// 1  3  -1 [-3  5  3] 6  7       5
		// 1  3  -1  -3 [5  3  6] 7       6
		// 1  3  -1 - 3  5 [3  6  7]      7
		

		vector<int> nums2 = { 1 };
		int k2 = 1;
		vector<int> ret2 = sol->maxSlidingWindow(nums2, k2);
		print_res(ret2);
		//Output : [1]
	}

	void print_res(vector<int>& res)
	{
		cout << "[";
		for (int i = 0; i < res.size(); ++i)
		{
			cout << res[i] << ",";
		}
		cout << "]" << endl;
	}
};



