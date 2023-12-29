#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _0062_unique_paths
{
public:
	int uniquePaths(int m, int n) {
		return 0;
	}

	void do_test(_0062_unique_paths* sol) {
		int m1 = 3;
		int n1 = 7;
		int res1 = sol->uniquePaths(m1, n1);
		cout << res1 << endl;
		// Output : 28
		

		int m2 = 3;
		int n2 = 2;
		int res2 = sol->uniquePaths(m2, n2);
		cout << res2 << endl;
		// Output : 3
		// Explanation : From the top - left corner, there are a total of 3 ways to reach the bottom - right corner :
		// 1. Right->Down->Down
		// 2. Down->Down->Right
		// 3. Down->Right->Down
	}
};


