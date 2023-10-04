#pragma once

#include <iostream>

using namespace std;


class _0070_climbing_stairs
{
public:
	int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }

        int first = 1;
        int second = 2;

        int result = 0;

        // for (int i = 2; i < n; i++) {
        for (int i = n - 3; i >= 0; i--) {
            result = first + second;
            first = second;
            second = result;
        }

        return result;
	}

	void do_test(_0070_climbing_stairs* sol)
	{
        int n1 = 2;
        int ret1 = sol->climbStairs(n1);
        cout << ret1 << endl;
        /*
        Output : 2
        Explanation : There are two ways to climb to the top.
        1. 1 step + 1 step
        2. 2 steps
        */

        int n2 = 3;
        int ret2 = sol->climbStairs(n2);
        cout << ret2 << endl;
        /*
        Output : 3
        Explanation : There are three ways to climb to the top.
        1. 1 step + 1 step + 1 step
        2. 1 step + 2 steps
        3. 2 steps + 1 step
        */
	}
};




