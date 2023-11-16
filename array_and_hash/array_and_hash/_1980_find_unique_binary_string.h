#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


class _1980_find_unique_binary_string
{
public:
	string findDifferentBinaryString(vector<string>& nums) {
		unordered_set<string> set;
		for (string s : nums) {
			set.insert(s);
		}

		int n = nums[0].size();
		string curr = "";
		string ans = "";
		dfs(curr, ans, 0, n, set);
		return ans;
	}

	bool dfs(string& curr, string& ans, int i, int n, unordered_set<string>& set) {
		if (i == n) {
			if (set.find(curr) != set.end()) {
				return true;
			}
			ans = curr;
			return false;
		}

		curr.push_back('0');
		if (!dfs(curr, ans, i + 1, n, set)) {
			return false;
		}
		curr.pop_back();

		curr.push_back('1');
		if (!dfs(curr, ans, i + 1, n, set)) {
			return false;
		}
		curr.pop_back();

		return true;
	}

	void do_test(_1980_find_unique_binary_string* sol) {
		vector<string> nums1 = { "01", "10" };
		string ret1 = sol->findDifferentBinaryString(nums1);
		cout << ret1 << endl;
		// Output : "11"
		// Explanation : "11" does not appear in nums. "00" would also be correct.
		

		vector<string> nums2 = { "00", "01" };
		string ret2 = sol->findDifferentBinaryString(nums2);
		cout << ret2 << endl;
		// Output : "11"
		// Explanation : "11" does not appear in nums. "10" would also be correct.
		

		vector<string> nums3 = { "111", "011", "001" };
		string ret3 = sol->findDifferentBinaryString(nums3);
		cout << ret3 << endl;
		// Output : "101"
		// Explanation : "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
	}
};
