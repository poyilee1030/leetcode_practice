#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class _0090_subsets_ii
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

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
        while ((i + 1 < nums.size()) && (nums[i] == nums[i + 1]))
            i++;
        dfs(nums, i + 1, curr, result);
    }

	void do_test(_0090_subsets_ii* sol)
	{
        vector<int> nums1 = { 1, 2, 2 };
        vector<vector<int>> ret1 = subsetsWithDup(nums1);
        print_res(ret1);
        //Output : [[],[1],[1,2],[1,2,2],[2],[2,2]]


        vector<int> nums2 = { 0 };
        vector<vector<int>> ret2 = subsetsWithDup(nums2);
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


