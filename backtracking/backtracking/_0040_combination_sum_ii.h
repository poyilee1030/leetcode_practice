#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class _0040_combination_sum_ii
{
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());

		vector<int> curr;
		vector<vector<int>> result;
		
		dfs(candidates, target, 0, 0, curr, result);
		return result;
	}

	void dfs(vector<int>& candidates, int target, int total, int i, vector<int>& curr, vector<vector<int>>& result)
	{
		if (total == target) {
			result.push_back(curr);
			return;
		}
		if (i >= candidates.size() || total > target) {
			return;
		}

		curr.push_back(candidates[i]);
		dfs(candidates, target, total + candidates[i], i + 1, curr, result);
		curr.pop_back();
		while ((i + 1 < candidates.size()) && (candidates[i] == candidates[i + 1]))
			i++;
		dfs(candidates, target, total, i + 1, curr, result);
	}

	void do_test(_0040_combination_sum_ii* sol)
	{
		vector<int> candidates1 = { 10, 1, 2, 7, 6, 1, 5 };
		int target1 = 8;
		vector<vector<int>> res1 = combinationSum2(candidates1, target1);
		print_res(res1);
		/*
		Output :
		[[1, 1, 6], [1, 2, 5], [1, 7], [2, 6]]
		*/

		vector<int> candidates2 = { 2, 5, 2, 1, 2 };
		int target2 = 5;
		vector<vector<int>> res2 = combinationSum2(candidates2, target2);
		print_res(res2);
		/*
		Output :
		[[1, 2, 2], [5]]
		*/
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
