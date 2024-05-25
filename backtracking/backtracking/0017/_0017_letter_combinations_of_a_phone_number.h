#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


class _0017_letter_combinations_of_a_phone_number
{
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        unordered_map<char, string> m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string curr = "";
        vector<string> result;

        dfs(digits, 0, m, curr, result);
        return result;
    }

    void dfs(string digits, int index, unordered_map<char, string>& m, string& curr, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(curr);
            return;
        }
        string str = m[digits[index]];
        for (int i = 0; i < str.size(); i++) {
            curr.push_back(str[i]);
            dfs(digits, index + 1, m, curr, result);
            curr.pop_back();
        }
    }

	void do_test(_0017_letter_combinations_of_a_phone_number *sol)
	{
		string digits1 = "23";
		vector<string> res1 = sol->letterCombinations(digits1);
		print_res(res1);
		//Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]

		string digits2 = "";
		vector<string> res2 = sol->letterCombinations(digits2);
		print_res(res2);
		//Output : []

		string digits3 = "2";
		vector<string> res3 = sol->letterCombinations(digits3);
		print_res(res3);
		//Output : ["a", "b", "c"]
	}

	void print_res(vector<string>& res)
	{
		cout << "[";
		for (int i = 0; i < res.size(); ++i)
		{
			cout << res[i];
			if (i < res.size() - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}
};



