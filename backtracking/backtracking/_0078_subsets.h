#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0078_subsets
{
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> curr;
		vector<vector<int>> result;
		dfs(nums, 0, curr, result);
		return result;
	}

	void dfs(vector<int>& nums, int i, vector<int>& curr, vector<vector<int>>& result) {
		if (i >= nums.size())
		{
			result.push_back(curr);
			return;
		}
		curr.push_back(nums[i]);
		dfs(nums, i + 1, curr, result);
		curr.pop_back();
		dfs(nums, i + 1, curr, result);
	}

	void do_test(_0078_subsets* sol)
	{
		vector<int> nums1 = { 1, 2, 3 };
		vector<vector<int>> ret1 = subsets(nums1);
		print_res(ret1);
		//Output : [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
		

		vector<int> nums2 = { 0 };
		vector<vector<int>> ret2 = subsets(nums2);
		print_res(ret2);
		//Output : [[], [0]]

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

