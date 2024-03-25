#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
	Given unsorted array, return length of longest consecutive sequence
	Ex. nums = [100,4,200,1,3,2] -> 4, longest is [1,2,3,4]

	Store in hash set, only check for longer seq if it's the beginning

	Time: O(n)
	Space: O(n)
*/

class _0128_longest_consecutive_sequence
{
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int>s(nums.begin(), nums.end());
		int longest = 0;
		for (auto& n : s) {
			//if this is the start of the sequence
			int oo = s.count(n - 1);
			if (!oo) {
				int length = 1;
				while (s.count(n + length))
					++length;
				longest = max(longest, length);
			}
		}
		return longest;
	}

	void do_test(_0128_longest_consecutive_sequence *sol)
	{
		vector<int> nums1 = { 100, 4, 200, 1, 3, 2 };
		int ret1 = sol->longestConsecutive(nums1);
		cout << ret1 << endl;
		//Output : 4
		//Explanation : The longest consecutive elements sequence is[1, 2, 3, 4].Therefore its length is 4.
		
		vector<int> nums2 = { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 };
		int ret2 = sol->longestConsecutive(nums2);
		cout << ret2 << endl;
		//Output : 9
	}
};
