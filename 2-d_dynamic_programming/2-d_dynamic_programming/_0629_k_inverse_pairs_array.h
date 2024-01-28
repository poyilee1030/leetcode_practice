#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class _0629_k_inverse_pairs_array
{
public:
	int kInversePairs(int n, int k) {
		vector<vector<long>> dp(n + 1, vector<long>(k + 1, 0));
		int mod = 1e9 + 7;

		for (int i = 0; i <= n; i++) {
			dp[i][0] = 1;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				if (j >= i)
					dp[i][j] = ((dp[i][j - 1] + dp[i - 1][j]) % mod - dp[i - 1][j - i] + mod) % mod;
				else
					dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
			}
		}
		return dp[n][k];
	}

	/*
	int kInversePairs(int n, int k) {
		vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
		int mod = 1e9 + 7;

		for (int i = 0; i <= n; i++) {
			dp[i][0] = 1;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				for (int m = 0; m <= min(j, i - 1); m++) {
					dp[i][j] = (dp[i][j] + dp[i - 1][j - m]) % mod;
				}
			}
		}
		return dp[n][k];
	}
	*/

	void do_test(_0629_k_inverse_pairs_array* sol) {
		int ret1 = sol->kInversePairs(3, 0);
		cout << ret1 << endl;
		// Output: 1

		int ret2 = sol->kInversePairs(3, 1);
		cout << ret2 << endl;
		// Output: 2

		int ret3 = sol->kInversePairs(1000, 1000);
		cout << ret3 << endl;
		// Output: 663677020
	}
};
