#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
    Given n pairs of parentheses, generate all combos of well-formed parentheses
    Ex. n = 3 -> ["((()))","(()())","(())()","()(())","()()()"], n = 1 -> ["()"]

    Backtracking, keep valid, favor trying opens, then try closes if still valid

    Time: O(2^n)
    Space: O(n)
*/

class _0022_generate_parentheses
{
public:
	vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, 0, 0, "", result);
        return result;
	}

    void generate(int n, int open, int close, string str, vector<string>& result) {
        if (open == n && close == n) {
            result.push_back(str);
            return;
        }
        if (open < n) {
            generate(n, open + 1, close, str + '(', result);
        }
        if (open > close) {
            generate(n, open, close + 1, str + ')', result);
        }
    }

	void do_test(_0022_generate_parentheses *sol)
	{
        int n1 = 3;
        vector<string> res1 = sol->generateParenthesis(n1);
        //Output : ["((()))", "(()())", "(())()", "()(())", "()()()"]
        print_res(res1);

        int n2 = 1;
        vector<string> res2 = sol->generateParenthesis(n2);
        //Output : ["()"]
        print_res(res2);
	}

    void print_res(vector<string>& res)
    {
        cout << "[";
        for (unsigned int i = 0; i < res.size(); ++i)
        {
            cout << res[i] << ",";
        }
        cout << "]" << endl;
    }
};


