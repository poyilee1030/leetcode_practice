#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
	Given array in range [0, n], return missing
	Ex. nums = [3,0,1] -> 2, nums = [0,1] -> 2

	Use the fact that XOR is its own inverse
	Ex. [0,1,3,4]
	Missing = 4^(0^0)^(1^1)^(2^3)^(3^4)
			= (4^4)^(0^0)^(1^1)^(3^3)^2
			= 0^0^0^0^2 = 2

	Time: O(n)
	Space: O(1)
*/

class _0268_missing_number
{
public:
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		int result = n;
		for (int i = 0; i < n; i++) {
			result ^= i ^ nums[i];
		}
		return result;
	}

	void do_test(_0268_missing_number* sol) {
		vector<int> nums1 = { 3, 0, 1 };
		int ret1 = sol->missingNumber(nums1);
		cout << ret1 << endl;
		/*
		Output : 2
		Explanation : n = 3 since there are 3 numbers, so all numbers are in the range[0, 3].
		              2 is the missing number in the range since it does not appear in nums.
		*/
		
		vector<int> nums2 = { 0, 1 };
		int ret2 = sol->missingNumber(nums2);
		cout << ret2 << endl;
		/*
		Output : 2
		Explanation : n = 2 since there are 2 numbers, so all numbers are in the range[0, 2]. 
					  2 is the missing number in the range since it does not appear in nums.
		*/
		
		vector<int> nums3 = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
		int ret3 = sol->missingNumber(nums3);
		cout << ret3 << endl;
		/*
		Output : 8
		Explanation : n = 9 since there are 9 numbers, so all numbers are in the range[0, 9]. 
		              8 is the missing number in the range since it does not appear in nums.
		*/
	}
};
