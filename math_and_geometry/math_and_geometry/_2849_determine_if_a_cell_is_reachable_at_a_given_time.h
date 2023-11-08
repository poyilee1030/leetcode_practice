#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _2849_determine_if_a_cell_is_reachable_at_a_given_time
{
public:
	bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
		int width = abs(sx - fx);
		int height = abs(sy - fy);
		if (width == 0 && height == 0 && t == 1) {
			return false;
		}
		return t >= max(width, height);
	}

	void do_test(_2849_determine_if_a_cell_is_reachable_at_a_given_time* sol) {
		//Input : sx = 2, sy = 4, fx = 7, fy = 7, t = 6
		bool ret1 = sol->isReachableAtTime(2, 4, 7, 7, 6);
		cout << ret1 << endl;
		/*
		Output : true
		Explanation : Starting at cell(2, 4), we can reach cell(7, 7) in exactly 6 seconds 
		by going through the cells depicted in the picture above.
		*/

		//Input : sx = 3, sy = 1, fx = 7, fy = 3, t = 3
		bool ret2 = sol->isReachableAtTime(3, 1, 7, 3, 3);
		cout << ret2 << endl;
		/*
		Output : false
		Explanation : Starting at cell(3, 1), it takes at least 4 seconds 
		to reach cell(7, 3) by going through the cells depicted in the picture above.
		Hence, we cannot reach cell(7, 3) at the third second.
		*/

		//Input : sx = 1, sy = 2, fx = 1, fy = 2, t = 1
		bool ret3 = sol->isReachableAtTime(1, 2, 1, 2, 1);
		cout << ret3 << endl;
		/*
		Output : false
		*/
	}
};
