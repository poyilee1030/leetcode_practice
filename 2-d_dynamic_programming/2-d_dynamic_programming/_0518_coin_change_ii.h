#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class _0518_coin_change_ii
{
public:
	/*
		DYNAMIC PROGRAMMING
		Time: O(n*m)
		Memory: O(m) where m = amount
	*/
	int change(int amount, vector<int>& coins) {
		int n = coins.size();
		vector<int> dp(amount + 1);
		dp[0] = 1;

		for (int j = n - 1; j >= 0; j--) {
			vector<int> nextDP(amount + 1);
			nextDP[0] = 1;

			for (int i = 1; i <= amount; i++) {
				nextDP[i] = dp[i];
				int x = i - coins[j];
				if (x >= 0) {
					nextDP[i] += nextDP[x];
				}
			}
			dp = nextDP;
		}
		return dp[amount];
	}

	/*
		DYNAMIC PROGRAMMING
		Time: O(n*m)
		Memory: O(n*m)
	*/
	/*
	int change(int amount, vector<int>& coins) {
		int n = coins.size();
		vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
		for (int j = 0; j < n; j++) {
			dp[j][0] = 1;
		}

		for (int j = n - 1; j >= 0; j--) {
			for (int i = 1; i <= amount; i++) {
				dp[j][i] = dp[j + 1][i];
				int x = i - coins[j];
				if (x >= 0) {
					dp[j][i] += dp[j][x];
				}
			}
		}
		return dp[0][amount];
	}
	*/

	void do_test(_0518_coin_change_ii* sol) {
		int amount1 = 5;
		vector<int> coins1 = { 1, 2, 5 };
		int ret1 = sol->change(amount1, coins1);
		cout << ret1 << endl;
		/*
		Output : 4
		Explanation : there are four ways to make up the amount :
		5 = 5
		5 = 2 + 2 + 1
		5 = 2 + 1 + 1 + 1
		5 = 1 + 1 + 1 + 1 + 1
		*/

		int amount2 = 3;
		vector<int> coins2 = { 2 };
		int ret2 = sol->change(amount2, coins2);
		cout << ret2 << endl;
		// Output : 0
		// Explanation : the amount of 3 cannot be made up just with coins of 2.
		
		int amount3 = 10;
		vector<int> coins3 = { 10 };
		int ret3 = sol->change(amount3, coins3);
		cout << ret3 << endl;
		// Output : 1
	}
};

