#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class _1838_frequency_of_the_most_frequent_element
{
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int ans = 0;
        long curr = 0;

        for (int right = 0; right < nums.size(); right++) {
            long target = nums[right];
            curr += target;

            while ((right - left + 1) * target - curr > k) {
                curr -= nums[left];
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }

	void do_test(_1838_frequency_of_the_most_frequent_element* sol) {
        vector<int> nums1 = { 1, 2, 4 };
        int ret1 = sol->maxFrequency(nums1, 5);
        cout << ret1 << endl;
        /*
        Output : 3
        Explanation : Increment the first element three times and the second element 
        two times to make nums = [4, 4, 4]. 4 has a frequency of 3.
        */
        
        vector<int> nums2 = { 1, 4, 8, 13 };
        int ret2 = sol->maxFrequency(nums2, 5);
        cout << ret2 << endl;
        /*
        Output : 2
        Explanation : There are multiple optimal solutions :
        - Increment the first element three times to make nums = [4, 4, 8, 13]. 4 has a frequency of 2.
        - Increment the second element four times to make nums = [1, 8, 8, 13]. 8 has a frequency of 2.
        - Increment the third element five times to make nums = [1, 4, 13, 13]. 13 has a frequency of 2.
        */
        
        vector<int> nums3 = { 3, 9, 6 };
        int ret3 = sol->maxFrequency(nums3, 2);
        cout << ret3 << endl;
        // Output : 1
	}
};
