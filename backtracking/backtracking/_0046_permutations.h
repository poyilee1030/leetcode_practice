#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class _0046_permutations
{
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> curr = {};
		backtrack(nums, curr, result);
		return result;
	}

	void backtrack(vector<int>& nums, vector<int>& curr, vector<vector<int>>& result) {
		if (curr.size() == nums.size()) {
			result.push_back(curr);
			return;
		}

		for (int num : nums) {
			if (find(curr.begin(), curr.end(), num) == curr.end()) {
				curr.push_back(num);
				backtrack(nums, curr, result);
				curr.pop_back();
			}
		}
	}

	void do_test(_0046_permutations* sol)
	{
		vector<int> nums1 = { 1, 2, 3 };
		vector<vector<int>> res1 = sol->permute(nums1);
		print_res(res1);
		//Output : [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
		
		vector<int> nums2 = { 0, 1 };
		vector<vector<int>> res2 = sol->permute(nums2);
		print_res(res2);
		//Output : [[0, 1], [1, 0]]
		
		vector<int> nums3 = { 1 };
		vector<vector<int>> res3 = sol->permute(nums3);
		print_res(res3);
		//Output : [[1]]
	}

	void print_res(vector<vector<int>> res)
	{
		cout << "[";
		for (int i = 0; i < res.size(); ++i)
		{
			cout << "[";
			vector<int> oo = res[i];
			for (int j = 0; j < oo.size(); ++j)
			{
				cout << oo[j];
				if (j != oo.size() - 1)
					cout << ",";
			}
			cout << "]";
			if (i != res.size() - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}
};



