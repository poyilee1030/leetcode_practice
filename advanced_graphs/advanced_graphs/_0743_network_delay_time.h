#pragma once

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

class _0743_network_delay_time
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<PII>> route(n + 1);
        for (auto t : times)
            route[t[0]].push_back( {t[1], t[2]});

        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.push({ 0, k });
        vector<int>resolved(n + 1, 0);
        int ans = 0;

        while (!pq.empty()) {
            auto x = pq.top();
            int d = x.first;
            int cur = x.second;
            pq.pop();

            if (resolved[cur] == 1)
                continue;
            resolved[cur] = 1;
            ans = max(ans, d);  // dist[cur] = d

            for (auto y: route[cur]) {
                int nxt = y.first;
                int weight = y.second;
                if (resolved[nxt])
                    continue;
                pq.push({ d + weight, nxt });
            }
        }

        for (int i = 1; i <= n; i++)
            if (resolved[i] == 0)
                return -1;

        return ans;
    }

	void do_test(_0743_network_delay_time* sol)
	{
        vector<vector<int>> times;
        int ret;
		
        times = { {2, 1, 1}, {2, 3, 1}, {3, 4, 1} };
        ret = sol->networkDelayTime(times, 4, 2);
		cout << ret << endl;
		// Output : 2

		times = { {1, 2, 1} };
		ret = sol->networkDelayTime(times, 2, 1);
		cout << ret << endl;
		// Output : 1

		times = { {1, 2, 1} };
		ret = sol->networkDelayTime(times, 2, 2);
		cout << ret << endl;
		// Output : -1
	}
};
