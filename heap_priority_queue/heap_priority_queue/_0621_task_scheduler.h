#pragma once

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class _0621_task_scheduler
{
public:
	int leastInterval(vector<char>& tasks, int n) {
		priority_queue<int> pq;
		queue<vector<int>> q;
		vector<int> counter(26);

		for (int i = 0; i < tasks.size(); ++i)
			++counter[tasks[i] - 'A'];
		for (int i = 0; i < 26; ++i) {
			if (counter[i])
				pq.push(counter[i]);
		}

		int time = 0;
		while (!q.empty() || !pq.empty()) {
			++time;
			if (!pq.empty()) {
				if (pq.top() - 1)
					q.push({ pq.top() - 1, time + n });
				pq.pop();
			}
			if (!q.empty() && q.front()[1] == time) {
				pq.push(q.front()[0]);
				q.pop();
			}
		}
		return time;
	}

	void do_test(_0621_task_scheduler *sol)
	{
		vector<char> tasks1 = { 'A', 'A', 'A', 'B', 'B', 'B' };
		int n1 = 2;
		int res1 = sol->leastInterval(tasks1, n1);
		cout << res1 << endl;;
		/*
		Output : 8
		Explanation :
		A->B->idle->A->B->idle->A->B
		There is at least 2 units of time between any two same tasks.
		*/

		vector<char> tasks2 = { 'A', 'A', 'A', 'B', 'B', 'B' };
		int n2 = 0;
		int res2 = sol->leastInterval(tasks2, n2);
		cout << res2 << endl;;
		/*
		Output : 6
		Explanation : On this case any permutation of size 6 would work since n = 0.
		['A', 'A', 'A', 'B', 'B', 'B']
		['A', 'B', 'A', 'B', 'A', 'B']
		['B', 'B', 'B', 'A', 'A', 'A']
		...
		And so on.
		*/
		
		vector<char> tasks3 = { 'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
		int n3 = 2;
		int res3 = sol->leastInterval(tasks3, n3);
		cout << res3 << endl;
		/*
		Output : 16
		Explanation :
		One possible solution is
		A->B->C->A->D->E->A->F->G->A->idle->idle->A->idle->idle->A
		*/

	}
};
