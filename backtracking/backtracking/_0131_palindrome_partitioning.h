#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class _0131_palindrome_partitioning
{
public:

	vector<vector<string>> partition(string s) {
		vector<string> curr;
		vector<vector<string>> result;
		dfs(s, 0, curr, result);
		return result;
	}

	void dfs(string s, int start, vector<string>& curr, vector<vector<string>>& result) {
		if (start == s.size()) {
			result.push_back(curr);
			return;
		}
		for (int i = start; i < s.size(); i++) {
			if (isPalindrome(s, start, i)) {
				string str = s.substr(start, i - start + 1);
				curr.push_back(str);
				dfs(s, i + 1, curr, result);
				curr.pop_back();
			}
		}
	}
	bool isPalindrome(string s, int left, int right) {
		while (left < right) {
			if (s[left] != s[right]) {
				return false;
			}
			left++;
			right--;
		}
		return true;
	}

	void do_test(_0131_palindrome_partitioning* sol)
	{
		string s1 = "aab";
		vector<vector<string>> res1 = sol->partition(s1);
		print_res(res1);
		//Output : [["a", "a", "b"], ["aa", "b"]]
		
		string s2 = "a";
		vector<vector<string>> res2 = sol->partition(s2);
		print_res(res2);
		//Output : [["a"]]
	}

	void print_res(vector<vector<string>> res)
	{
		cout << "[";
		for (int i = 0; i < res.size(); ++i)
		{
			cout << "[";
			vector<string> oo = res[i];
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
