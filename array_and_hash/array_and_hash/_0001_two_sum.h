#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class _0001_two_sum
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> mp; // val -> index

        for (int i = 0; i < n; i++)
        {
            int compliment = target - nums[i];
            if (mp.find(compliment) != mp.end())
            {
                return { mp[compliment], i };
            }
            mp.insert({ nums[i], i });
        }
        return {};
    }

    void do_test(_0001_two_sum *sol)
    {
        vector<int> nums1 = { 2, 7, 11, 15 };
        int target1 = 9;
        vector<int> ret1 = sol->twoSum(nums1, target1);
        //Output: [0, 1]
        sol->print_result(ret1);

        vector<int> nums2 = { 3, 2, 4 };
        int target2 = 6;
        vector<int> ret2 = sol->twoSum(nums2, target2);
        //Output: [1, 2]
        sol->print_result(ret2);

        vector<int> nums3 = { 3, 3 };
        int target3 = 6;
        vector<int> ret3 = sol->twoSum(nums3, target3);
        //Output: [0, 1]
        sol->print_result(ret3);
    }

    void print_result(vector<int>& result)
    {
        cout << "[";
        for (int i : result)
        {
            cout << i << ",";
        }
        cout << "]" << endl;
    }
};
