#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0973_k_closest_points_to_origin
{
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		vector<vector<int>> triples;
		for (auto& p : points)
			triples.push_back({ p[0] * p[0] + p[1] * p[1], p[0], p[1] });
		// Min heap of vectors (triples). This constructor takes O(n) time (n = len(v))
		priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq(triples.begin(), triples.end());
		vector<vector<int>> res;
		while (k--) {
			vector<int> el = pq.top();
			pq.pop();
			res.push_back({ el[1], el[2] });
		}
		return res;
	}

	void do_test(_0973_k_closest_points_to_origin* sol)
	{
		vector<vector<int>> points1 = { {1, 3} ,{-2, 2} };
		int k1 = 1;
		vector<vector<int>> res1 = sol->kClosest(points1, k1);
		print_res(res1);
		/*
		Output : [[-2, 2]]
		Explanation :
			The distance between(1, 3) and the origin is sqrt(10).
			The distance between(-2, 2) and the origin is sqrt(8).
			Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
			We only want the closest k = 1 points from the origin, so the answer is just [[-2, 2]].
		*/
		
		vector<vector<int>> points2 = { {3, 3}, {5, -1}, {-2, 4} };
		int k2 = 2;
		vector<vector<int>> res2 = sol->kClosest(points2, k2);
		print_res(res2);
		/*
		Output : [[3, 3], [-2, 4]]
		Explanation : The answer [[-2, 4], [3, 3]] would also be accepted.
		*/
	}

	void print_res(vector<vector<int>> &res)
	{
		cout << "[";
		for (int i = 0; i < res.size(); ++i)
		{
			cout << "[";
			vector<int> oo = res[i];
			for (int j = 0; j < oo.size(); ++j)
			{
				cout << oo[j];

				if (j < oo.size() - 1)
					cout << ",";
			}
			cout << "]";
			if (i < res.size() - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}
};


