#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _2864_maximum_odd_binary_number
{
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        if (n <= 1)
            return s;
        int l = 0;
        int r = n - 1;
        while (l < r) {
            while (l < n && s[l] == '1')
                l++;

            while (r >= 0 && s[r] == '0')
                r--;

            if (l >= r)
                break;

            swap(s[l], s[r]);
        }

        if (s[n - 1] == '0')
            swap(s[l - 1], s[n - 1]);
        return s;
    }

	void do_test(_2864_maximum_odd_binary_number* sol) {
        string ret = sol->maximumOddBinaryNumber("010");
        cout << ret << endl;
        // Output : "001"

        ret = sol->maximumOddBinaryNumber("0101");
        cout << ret << endl;
        // Output : "1001"

        ret = sol->maximumOddBinaryNumber("1");
        cout << ret << endl;
        // Output : "1"

        ret = sol->maximumOddBinaryNumber("110");
        cout << ret << endl;
        // Output : "101

        ret = sol->maximumOddBinaryNumber("011");
        cout << ret << endl;
        // Output : "101

        ret = sol->maximumOddBinaryNumber("10");
        cout << ret << endl;
        // Output : "01

        ret = sol->maximumOddBinaryNumber("100");
        cout << ret << endl;
        // Output : "001
	}
};
