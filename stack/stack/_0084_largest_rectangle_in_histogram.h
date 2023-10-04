#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
Given array of heights, return area of largest rectangle
Ex. heights = [2,1,5,6,2,3] -> 10 (5 x 2 at index 2 and 3)

Monotonic incr stack, if curr height lower extend back, find max area

Time: O(n)
Space: O(n)
*/

class _0084_largest_rectangle_in_histogram
{
public:
	int largestRectangleArea(vector<int>& heights) {
        // pair: [index, height]
        stack<pair<int, int>> stk;
        int result = 0;

        for (int i = 0; i < heights.size(); i++) {
            int start = i;

            while (!stk.empty() && stk.top().second > heights[i]) {
                int index = stk.top().first;
                int width = i - index;
                int height = stk.top().second;
                stk.pop();

                result = max(result, height * width);
                start = index;
            }

            stk.push({ start, heights[i] });
        }

        while (!stk.empty()) {
            int width = heights.size() - stk.top().first;
            int height = stk.top().second;
            stk.pop();

            result = max(result, height * width);
        }

        return result;
	}

	void do_test(_0084_largest_rectangle_in_histogram* sol)
	{
		vector<int> heights1 = { 2, 1, 5, 6, 2, 3 };
		int ret1 = sol->largestRectangleArea(heights1);
		//Output: 10
		cout << ret1 << endl;

		vector<int> heights2 = { 2, 4 };
		int ret2 = sol->largestRectangleArea(heights2);
		//Output: 4
		cout << ret2 << endl;
	}
};



