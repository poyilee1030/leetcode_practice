#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _1535_find_the_winner_of_an_array_game
{
public:
	int getWinner(vector<int>& arr, int k) {
		int maxElement = arr[0];
		for (int i = 1; i < arr.size(); i++) {
			maxElement = max(maxElement, arr[i]);
		}

		int curr = arr[0];
		int winstreak = 0;

		for (int i = 1; i < arr.size(); i++) {
			int opponent = arr[i];

			if (curr > opponent) {
				winstreak++;
			}
			else {
				curr = opponent;
				winstreak = 1;
			}

			if (winstreak == k || curr == maxElement) {
				return curr;
			}
		}

		return -1;
	}

	void do_test(_1535_find_the_winner_of_an_array_game* sol) {
		vector<int> arr1 = { 2, 1, 3, 5, 4, 6, 7 };
		int k1 = 2;
		int ret1 = sol->getWinner(arr1, k1);
		cout << ret1 << endl;
		/*
		Output : 5
		Explanation : Let's see the rounds of the game:
		Round | arr | winner | win_count
		1 | [2, 1, 3, 5, 4, 6, 7] | 2 | 1
		2 | [2, 3, 5, 4, 6, 7, 1] | 3 | 1
		3 | [3, 5, 4, 6, 7, 1, 2] | 5 | 1
		4 | [5, 4, 6, 7, 1, 2, 3] | 5 | 2
		So we can see that 4 rounds will be played and 5 is the winner because it wins 2 consecutive games.
		*/
		
		vector<int> arr2 = { 3, 2, 1 };
		int k2 = 10;
		int ret2 = sol->getWinner(arr2, k2);
		cout << ret2 << endl;
		// Output : 3
		// Explanation : 3 will win the first 10 rounds consecutively.

		vector<int> arr3 = { 1, 25, 35, 42, 68, 70 };
		int k3 = 1;
		int ret3 = sol->getWinner(arr3, k3);
		cout << ret3 << endl;
		// Output : 25
	}
};
