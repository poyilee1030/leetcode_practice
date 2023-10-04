#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
	Given elevation map array, compute trapped water
	Ex. height = [0,1,0,2,1,0,1,3,2,1,2,1] -> 6

	2 pointers, outside in, track max left/right
	For lower max, curr only dependent on that one
	Compute height of these, iterate lower one

	Time: O(n)
	Space: O(1)
*/

class _0042_trapping_rain_water
{
public:
	int trap(vector<int>& height)
	{
		int i = 0;
		int j = height.size() - 1;

		int maxLeft = height[i];
		int maxRight = height[j];

		int result = 0;

		while (i < j) {
			if (maxLeft <= maxRight) {
				i++;
				maxLeft = max(maxLeft, height[i]);
				result += maxLeft - height[i];
			}
			else {
				j--;
				maxRight = max(maxRight, height[j]);
				result += maxRight - height[j];
			}
		}

		return result;
	}

	void do_test(_0042_trapping_rain_water* sol)
	{
		vector<int> height1 = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
		int ret1 = sol->trap(height1);
		cout << ret1 << endl;
		//Output : 6
		//Explanation : The above elevation map(black section) is represented by array[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1].In this case, 6 units of rain water(blue section) are being trapped.
		

		vector<int> height2 = { 4, 2, 0, 3, 2, 5 };
		int ret2 = sol->trap(height2);
		cout << ret2 << endl;
		//Output : 9
	}
};
