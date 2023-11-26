#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _1685_sum_of_absolute_differences_in_a_sorted_array
{
public:
	vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> array(n, vector<int>(n, 0));

		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				array[i][j] = abs(nums[i] - nums[j]);
			}
		}

		vector<int> result;
		for (int i = 0; i < nums.size(); i++) {
			int tmp = 0;
			for (int j = i + 1; j < nums.size(); j++) {
				tmp += array[i][j];
			}
			for (int j = i - 1; j >= 0; j--) {
				tmp += array[j][i];
			}
			result.push_back(tmp);
		}
		return result;
	}

	void do_test(_1685_sum_of_absolute_differences_in_a_sorted_array* sol) {
		vector<int> nums1 = { 2, 3, 5 };
		vector<int> ret1 = sol->getSumAbsoluteDifferences(nums1);
		print_result(ret1);
		/*
		Output : [4, 3, 5]
		Explanation : Assuming the arrays are 0 - indexed, then
		result[0] = | 2 - 2 | +| 2 - 3 | +| 2 - 5 | = 0 + 1 + 3 = 4,
		result[1] = | 3 - 2 | +| 3 - 3 | +| 3 - 5 | = 1 + 0 + 2 = 3,
		result[2] = | 5 - 2 | +| 5 - 3 | +| 5 - 5 | = 3 + 2 + 0 = 5.
		*/
		
		vector<int> nums2 = { 1, 4, 6, 8, 10 };
		vector<int> ret2 = sol->getSumAbsoluteDifferences(nums2);
		print_result(ret2);
		// Output : [24, 15, 13, 15, 21]
	}

	void print_result(vector<int>& res)
	{
		cout << "[";
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i];
			if (i < res.size() - 1) {
				cout << ",";
			}
		}
		cout << "]" << endl;
	}
};
