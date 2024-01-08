#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class _0518_coin_change_ii
{
public:
	int change(int amount, vector<int>& coins) {
		return 0;
	}

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

