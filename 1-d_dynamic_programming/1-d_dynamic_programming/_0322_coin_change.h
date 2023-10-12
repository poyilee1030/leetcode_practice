#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0322_coin_change
{
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, amount + 1);
		dp[0] = 0;

		for (int i = 1; i < amount + 1; i++) {
			for (int j = 0; j < coins.size(); j++) {
				if (i - coins[j] >= 0) {
					dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
				}
			}
		}

		if (dp[amount] == amount + 1) {
			return -1;
		}
		return dp[amount];
	}

	void do_test(_0322_coin_change* sol)
	{
		vector<int> coins1 = { 1, 2, 5 };
		int amount1 = 11;
		int ret1 = sol->coinChange(coins1, amount1);
		cout << ret1 << endl;
		//Output : 3
		//Explanation : 11 = 5 + 5 + 1
		

		vector<int> coins2 = { 2 };
		int amount2 = 3;
		int ret2 = sol->coinChange(coins2, amount2);
		cout << ret2 << endl;
		//Output : -1
		

		vector<int> coins3 = { 1 };
		int amount3 = 0;
		int ret3 = sol->coinChange(coins3, amount3);
		cout << ret3 << endl;
		//Output : 0
	}
};

