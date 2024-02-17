#pragma once

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class _1642_furthest_building_you_can_reach
{
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        // 預設由大到小排列
        priority_queue<int> pq;

        /*
        由小到大可以宣告如下
        priority_queue<int, vector<int>, greater<int>> pq;
        */

        for (int i = 0; i < heights.size() - 1; i++) {
            int diff = heights[i + 1] - heights[i];
            if (diff <= 0) {
                continue;
            }
            
            pq.push(diff);
            bricks -= diff;

            if (bricks < 0) {
                if (ladders == 0)
                    return i;
                
                ladders--;
                int b = pq.top();
                pq.pop();
                bricks += b;
            }
        }

        return heights.size() - 1;
    }
    // Time Limited Exceeded
    /*
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        return dfs(heights, bricks, ladders, 0);
    }

    int dfs(vector<int>& heights, int bricks, int ladders, int idx) {
        if (idx == heights.size() - 1) {
            return idx;
        }

        int r1 = idx, r2 = idx, r3 = idx;
        if (heights[idx] >= heights[idx + 1]) {
            r1 = dfs(heights, bricks, ladders, idx + 1);
        }
        else {
            int diff = heights[idx + 1] - heights[idx];
            if (bricks - diff >= 0) {
                r2 = dfs(heights, bricks - diff, ladders, idx + 1);
            }
            if (ladders - 1 >= 0) {
                r3 = dfs(heights, bricks, ladders - 1, idx + 1);
            }
        }
        return max(r1, max(r2, r3));
    }
    */

	void do_test(_1642_furthest_building_you_can_reach* sol) {
        vector<int> heights1 = { 4, 2, 7, 6, 9, 14, 12 };
        int ret1 = sol->furthestBuilding(heights1, 5, 1);
        cout << ret1 << endl;
        /*
        Output: 4
        Explanation : Starting at building 0, you can follow these steps :
            -Go to building 1 without using ladders nor bricks since 4 >= 2.
            - Go to building 2 using 5 bricks.You must use either bricks or ladders because 2 < 7.
            - Go to building 3 without using ladders nor bricks since 7 >= 6.
            - Go to building 4 using your only ladder.You must use either bricks or ladders because 6 < 9.
            It is impossible to go beyond building 4 because you do not have any more bricks or ladders.
        */

        vector<int> heights2 = { 4, 12, 2, 7, 3, 18, 20, 3, 19 };
        int ret2 = sol->furthestBuilding(heights2, 10, 2);
        cout << ret2 << endl;
        //Output : 7

        vector<int> heights3 = { 14, 3, 19, 3 };
        int ret3 = sol->furthestBuilding(heights3, 17, 0);
        cout << ret3 << endl;
        //Output : 3

        vector<int> heights4 = { 1, 5, 1, 2, 3, 4,10000 };
        int ret4 = sol->furthestBuilding(heights4, 4, 1);
        cout << ret4 << endl;
        // Output : 5
	}
};
