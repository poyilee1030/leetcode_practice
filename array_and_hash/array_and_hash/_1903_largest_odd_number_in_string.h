#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;


class _1903_largest_odd_number_in_string
{
public:
    string largestOddNumber(string num) {
        int r = -1;
        for (int i = num.size() - 1; i >= 0; i--) {
            char c = num[i];
            if (c == '1' || c == '3' || c == '5' || c == '7' || c == '9') {
                r = i + 1;
                break;
            }
        }
        if (r < 0) {
            return "";
        }
        else {
            return num.substr(0, r);
        }
    }

	void do_test(_1903_largest_odd_number_in_string* sol) {
        string num1 = "52";
        string ret1 = sol->largestOddNumber(num1);
        cout << ret1 << endl;
        // Output : "5"
        // Explanation : The only non - empty substrings are "5", "2", and "52". "5" is the only odd number.
        

        string num2 = "4206";
        string ret2 = sol->largestOddNumber(num2);
        cout << ret2 << endl;
        // Output : ""
        // Explanation : There are no odd numbers in "4206".
        

        string num3 = "35427";
        string ret3 = sol->largestOddNumber(num3);
        cout << ret3 << endl;
        // Output : "35427"
        // Explanation : "35427" is already an odd number.

        string num4 = "7542351161";
        string ret4 = sol->largestOddNumber(num4);
        cout << ret4 << endl;
	}
};
