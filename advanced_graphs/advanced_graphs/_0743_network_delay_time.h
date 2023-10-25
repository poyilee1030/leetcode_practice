#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0743_network_delay_time
{
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		return 0;
	}

	void do_test(_0743_network_delay_time* sol)
	{
		vector<vector<int>> times1 = { {2, 1, 1}, {2, 3, 1}, {3, 4, 1} };
		int n1 = 4;
		int k1 = 2;
		int ret1 = sol->networkDelayTime(times1, n1, k1);
		cout << ret1 << endl;
		// Output : 2

		vector<vector<int>> times2 = { {1, 2, 1} };
		int n2 = 2;
		int k2 = 1;
		int ret2 = sol->networkDelayTime(times2, n2, k2);
		cout << ret2 << endl;
		// Output : 1

		vector<vector<int>> times3 = { {1, 2, 1} };
		int n3 = 2;
		int k3 = 2;
		int ret3 = sol->networkDelayTime(times3, n3, k3);
		cout << ret3 << endl;
		// Output : -1
	}
};
