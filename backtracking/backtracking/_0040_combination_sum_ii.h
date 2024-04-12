#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;


class _0040_combination_sum_ii
{
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());

		vector<int> curr;
		vector<vector<int>> ans;
		
		dfs_style2(candidates, target, 0, 0, curr, ans);
		return ans;
	}

	// style 1
	void dfs_style1(vector<int>& candidates, int target, int i, int total, vector<int>& curr, vector<vector<int>>& ans) {
		if (total == target) {
			ans.push_back(curr);
			return;
		}
		if (i >= candidates.size() || total > target) {
			return;
		}

		curr.push_back(candidates[i]);
		dfs_style1(candidates, target, i + 1, total + candidates[i], curr, ans);
		curr.pop_back();
		while ((i + 1 < candidates.size()) && (candidates[i] == candidates[i + 1]))
			i++;
		dfs_style1(candidates, target, i + 1, total, curr, ans);
	}
	

	// style 2
	void dfs_style2(vector<int>& candidates, int target, int i, int total, vector<int>& curr, vector<vector<int>>& ans) {
        if (total == target) {
            ans.push_back(curr);
            return;
        }
        if (total > target) {
            return;
        }
        
        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j-1])
                continue;
            curr.push_back(candidates[j]);
			dfs_style2(candidates, target, j + 1, total + candidates[j], curr, ans);
            curr.pop_back();
        }
    }

	void do_test(_0040_combination_sum_ii* sol)
	{
		vector<int> candidates;
		vector<vector<int>> ret;
		
		candidates = { 10, 1, 2, 7, 6, 1, 5 };
		ret = combinationSum2(candidates, 8);
		print_vector_of_vector(ret);
		// Output : [[1, 1, 6], [1, 2, 5], [1, 7], [2, 6]]
		
		candidates = { 2, 5, 2, 1, 2 };
		ret = combinationSum2(candidates, 5);
		print_vector_of_vector(ret);
		// Output : [[1, 2, 2], [5]]
	}
};
