#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// time complexity before use cache = O(n^2)
// n element, and each i we can do cooldown or buy/sell

// after use cache, time complexity = O(n)
// because the cache key is (idx, buy/sell)
//                           ¡ô      ¡ô
//                           n      2
//                      so O(n*2) = O(n)


class _0309_best_time_to_buy_and_sell_stock_with_cooldown
{
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<unordered_map<bool, int>> cache(n);
		bool buying = true;
		return dfs(prices, 0, buying, cache);
	}

	int dfs(vector<int>& prices, int t, bool buying, vector<unordered_map<bool, int>>& cache) {
		if (t >= prices.size()) {
			return 0;
		}

		if (cache[t].find(buying) != cache[t].end()) {
			return cache[t][buying];
		}

		int res = 0;
		int b = dfs(prices, t + 1, buying, cache);
		if (buying) {
			int a = dfs(prices, t + 1, !buying, cache) - prices[t];
			cache[t][buying] = res = max(a, b);
		}
		else {
			int a = dfs(prices, t + 2, !buying, cache) + prices[t];
			cache[t][buying] = res = max(a, b);
		}
		return res;
	}

	void do_test(_0309_best_time_to_buy_and_sell_stock_with_cooldown* sol) {
		vector<int> prices1 = { 1, 2, 3, 0, 2 };
		int ret1 = sol->maxProfit(prices1);
		cout << ret1 << endl;
		// Output : 3
		// Explanation : transactions = [buy, sell, cooldown, buy, sell]

		vector<int> prices2 = { 1 };
		int ret2 = sol->maxProfit(prices2);
		cout << ret2 << endl;
		// Output : 0
	}
};
