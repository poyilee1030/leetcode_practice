#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _1046_last_stone_weight
{
public:
	int lastStoneWeight(vector<int>& stones) {
		priority_queue<int> pq;
		for (int i = 0; i < stones.size(); i++) {
			pq.push(stones[i]);
		}

		while (pq.size() > 1) {
			int y = pq.top();
			pq.pop();
			int x = pq.top();
			pq.pop();
			if (y > x) {
				pq.push(y - x);
			}
		}

		if (pq.empty()) {
			return 0;
		}
		return pq.top();
	}

	void do_test(_1046_last_stone_weight* sol)
	{
		vector<int> stones1 = { 2, 7, 4, 1, 8, 1 };
		int res1 = sol->lastStoneWeight(stones1);
		cout << res1 << endl;
		/*
		Output : 1
		Explanation :
		We combine 7 and 8 to get 1 so the array converts to[2, 4, 1, 1, 1] then,
		we combine 2 and 4 to get 2 so the array converts to[2, 1, 1, 1] then,
		we combine 2 and 1 to get 1 so the array converts to[1, 1, 1] then,
		we combine 1 and 1 to get 0 so the array converts to[1] then that's the value of the last stone.
		*/
		
		vector<int> stones2 = { 1 };
		int res2 = sol->lastStoneWeight(stones2);
		cout << res2 << endl;
		// Output: 1
	}
};
