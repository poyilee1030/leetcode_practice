#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Given int array, return all unique triplets that sum to 0
    Ex. nums = [-1,0,1,2,-1,-4] -> [[-1,-1,2],[-1,0,1]]

    Sort, for each i, have j & k go outside in, check for 0 sums

    Time: O(n^2)
    Space: O(n)
*/

class _0015_3sum
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 3) {
            return result;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i-1] == nums[i]) {
                continue;
            }

            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    result.push_back({ nums[i], nums[j], nums[k] });

                    while (j < k && nums[j] == nums[j+1]) {
                        j++;
                    }
                    j++;

                    while (j < k && nums[k-1] == nums[k]) {
                        k--;
                    }
                    k--;
                }
            }
        }

        return result;
    }

    void do_test(_0015_3sum* sol)
    {
        vector<int> nums1 = { -1, 0, 1, 2, -1, -4 };
        vector<vector<int>> ret1 = sol->threeSum(nums1);
        print_result(ret1);
        /*
        Output : [[-1, -1, 2], [-1, 0, 1]]
        Explanation :
        nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
        nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
        nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
        The distinct triplets are[-1, 0, 1] and [-1, -1, 2].
        Notice that the order of the output and the order of the triplets does not matter.
        */

        vector<int> nums2 = { 0, 1, 1 };
        vector<vector<int>> ret2 = sol->threeSum(nums2);
        print_result(ret2);
        //Output : []
        //Explanation : The only possible triplet does not sum up to 0.

        vector<int> nums3 = { 0, 0, 0 };
        vector<vector<int>> ret3 = sol->threeSum(nums3);
        print_result(ret3);
        //Output : [[0, 0, 0]]
        //Explanation : The only possible triplet sums up to 0.
    }

    void print_result(vector<vector<int>>& result)
    {
        cout << "[";
        for (int i = 0; i < result.size(); ++i)
        {
            cout << "[";
            vector<int> one_res = result[i];
            for (unsigned int j = 0; j < one_res.size(); ++j)
            {
                cout << one_res[j] << ",";
            }
            cout << "],";
        }
        cout << "]\n";
    }
};
