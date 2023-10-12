#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class _0091_decode_ways
{
public:
	int numDecodings(string s) {
		if (s[0] == '0') {
			return 0;
		}

		int n = s.size();

		vector<int> dp(n + 1);
		dp[0] = 1;
		dp[1] = 1;

		for (int i = 2; i <= n; i++) {
			int ones = stoi(s.substr(i - 1, 1));
			if (ones >= 1 && ones <= 9) {
				dp[i] += dp[i - 1];
			}
			int tens = stoi(s.substr(i - 2, 2));
			if (tens >= 10 && tens <= 26) {
				dp[i] += dp[i - 2];
			}
		}

		return dp[n];
	}

	void do_test(_0091_decode_ways* sol)
	{
		string s0 = "11111";
		int ret0 = sol->numDecodings(s0);
		cout << ret0 << endl;
		//Output: 8

		string s1 = "12";
		int ret1 = sol->numDecodings(s1);
		cout << ret1 << endl;
		//Output: 2
		//Explanation : "12" could be decoded as "AB" (1 2) or "L" (12).

		string s2 = "226";
		int ret2 = sol->numDecodings(s2);
		cout << ret2 << endl;
		//Output : 3
		//Explanation : "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
		
		string s3 = "06";
		int ret3 = sol->numDecodings(s3);
		cout << ret3 << endl;
		//Output : 0
		//Explanation : "06" cannot be mapped to "F" because of the leading zero("6" is different from "06").
	}
};



