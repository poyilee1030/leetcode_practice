#pragma once

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class _0621_task_scheduler
{
public:
	/* leetcode: 48ms
	int leastInterval(vector<char>& tasks, int n) {
		unordered_map<char, int>Map;
		for (auto ch : tasks)
			Map[ch]++;

		int maxFreq = 0;
		for (auto a : Map)
			maxFreq = max(maxFreq, a.second);

		int result = (maxFreq - 1) * (n + 1);
		int count = 0;
		for (auto a : Map)
		{
			if (a.second == maxFreq)
				count++;
		}
		return max(result + count, (int)tasks.size());
	}
	*/

	// 全模擬，較好記，leetcode: 82ms
	int leastInterval(vector<char>& tasks, int n) {
		unordered_map<char, int> freq;
		for (char ch : tasks) {
			freq[ch]++;
		}

		n = n + 1;

		priority_queue<int> pq;
		for (auto it = freq.begin(); it != freq.end(); it++) {
			pq.push(it->second);
		}

		int count = 0;
		while (!pq.empty()) {
			int k = min((int)pq.size(), n);
			vector<int> tmp;
			for (int i = 0; i < k; i++) {
				int f = pq.top();
				pq.pop();
				f--;
				if (f > 0)
					tmp.push_back(f);
			}

			if (tmp.size() > 0)
				count += n;
			else
				count += k;

			for (auto x : tmp)
				pq.push(x);
		}

		return count;
	}

	void do_test(_0621_task_scheduler *sol)
	{
		vector<char> tasks;
		int ret;

		tasks = { 'A', 'A', 'A', 'B', 'B', 'B' };
		ret = sol->leastInterval(tasks, 2);
		cout << ret << endl;;
		/*
		Output : 8
		Explanation :
		A->B->idle->A->B->idle->A->B
		There is at least 2 units of time between any two same tasks.
		*/

		tasks = { 'A', 'A', 'A', 'B', 'B', 'B' };
		ret = sol->leastInterval(tasks, 0);
		cout << ret << endl;;
		/*
		Output : 6
		Explanation : On this case any permutation of size 6 would work since n = 0.
		['A', 'A', 'A', 'B', 'B', 'B']
		['A', 'B', 'A', 'B', 'A', 'B']
		['B', 'B', 'B', 'A', 'A', 'A']
		...
		And so on.
		*/
		
		tasks = { 'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
		ret = sol->leastInterval(tasks, 2);
		cout << ret << endl;
		/*
		Output : 16
		Explanation :
		One possible solution is
		A->B->C->A->D->E->A->F->G->A->idle->idle->A->idle->idle->A
		*/

	}
};
