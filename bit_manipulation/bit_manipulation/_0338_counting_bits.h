#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0338_counting_bits
{
public:
	vector<int> countBits(int n) {
		vector<int> q;
		return q;
	}

	void do_test(_0338_counting_bits* sol)
	{
		int n1 = 2;
		vector<int> ret1 = sol->countBits(n1);
		print_res(ret1);
		/*
		Output : [0, 1, 1]
		Explanation :
			0 -- > 0
			1 -- > 1
			2 -- > 10
		*/

		int n2 = 5;
		vector<int> ret2 = sol->countBits(n2);
		print_res(ret2);
		/*
		Output : [0, 1, 1, 2, 1, 2]
		Explanation :
			0 -- > 0
			1 -- > 1
			2 -- > 10
			3 -- > 11
			4 -- > 100
			5 -- > 101
		*/		
	}

	void print_res(vector<int>& res) {
		cout << "[";
		for (int i = 0; i < res.size(); i++) {
			cout << res[i];
			if (i < res.size() - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}
};
