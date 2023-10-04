#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

/*
    Given s w/ '(, ), {, }, [, ]', determine if valid
    Ex. s = "()[]{}" -> true, s = "(]" -> false

    Stack of opens, check for matching closes & validity

    Time: O(n)
    Space: O(n)
*/

class _0020_valid_parentheses
{
public:
	bool isValid(string s) {
        stack<char> open;
        unordered_map<char, char> parens = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        for (const auto& c : s) {
            if (parens.find(c) != parens.end()) {
                // if input starts with a closing bracket.
                if (open.empty()) {
                    return false;
                }

                if (open.top() != parens[c]) {
                    return false;
                }

                open.pop();
            }
            else {
                open.push(c);
            }
        }

        return open.empty();
	}

	void do_test(_0020_valid_parentheses* sol)
	{
		string s1 = "()";
		bool ret1 = sol->isValid(s1);
		cout << ret1 << endl;
		//Output : true
		
		string s2 = "()[]{}";
		bool ret2 = sol->isValid(s2);
		cout << ret2 << endl;
		//Output : true
		
		string s3 = "(]";
		bool ret3 = sol->isValid(s3);
		cout << ret3 << endl;
		//Output : false
	}
};
