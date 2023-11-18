#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0121_best_time_to_buy_and_sell_stock
{
public:
	int maxProfit(vector<int>& prices) {
		int maxP = 0, l = 0, r = 0;
		while (r < prices.size()) {
			if (prices[r] > prices[l])
				maxP = max(maxP, prices[r] - prices[l]);
			else
				l = r;
			++r;
		}
		return maxP;
	}

	void do_test(_0121_best_time_to_buy_and_sell_stock* sol)
	{
		vector<int> prices1 = { 7, 1, 5, 3, 6, 4 };
		int ret1 = sol->maxProfit(prices1);
		//Output : 5
		cout << ret1 << endl;
		//Explanation : Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5.
		//Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
		

		vector<int> prices2 = { 7, 6, 4, 3, 1 };
		int ret2 = sol->maxProfit(prices2);
		//Output : 0
		cout << ret2 << endl;
	}
};





