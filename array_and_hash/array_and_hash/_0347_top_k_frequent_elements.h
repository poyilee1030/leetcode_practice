#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class _0347_top_k_frequent_elements
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            int v = m[nums[i]];
            v++;
            m[nums[i]] = v;
            //m[nums[i]]++;
        }

        vector<vector<int>> buckets(n + 1);
        for (auto it = m.begin(); it != m.end(); it++)
            buckets[it->second].push_back(it->first);

        vector<int> result;
        for (int i = n; i >= 0; i--) {
            if (result.size() >= k)
                break;
            if (!buckets[i].empty())
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
        }
        return result;
    }

    void do_test(_0347_top_k_frequent_elements *sol) {
        vector<int> nums;
        vector<int> ret;

        nums = { 1, 1, 1, 2, 2, 3 };
        ret = sol->topKFrequent(nums, 2);
        //Output: [0, 1]
        print_vector(ret);

        nums = { 1 };
        ret = sol->topKFrequent(nums, 1);
        //Output: [1, 2]
        print_vector(ret);
    }
};
