#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class _0309_best_time_to_buy_and_sell_stock_with_cooldown
{
public:
	int maxProfit(vector<int>& prices) {
		return 0;
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
