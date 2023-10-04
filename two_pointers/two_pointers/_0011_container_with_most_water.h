#pragma once

#include <iostream>
#include <vector>

using namespace std;

class _0011_container_with_most_water
{
public:
	int maxArea(vector<int>& height)
	{
		int l = 0;
		int r = height.size() - 1;
		int w = r - l;
		int h = min(height[l], height[r]);
		int max_a = w * h;
		while (l < r)
		{
			if (height[l] > height[r])
			{
				--r;
			}
			else
			{
				++l;
			}
			int w = r - l;
			int h = min(height[l], height[r]);
			int a = w * h;
			if (a > max_a)
			{
				max_a = a;
			}
		}
		return max_a;
	}

	void do_test(_0011_container_with_most_water* sol)
	{
		vector<int> height1 = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
		int ret1 = sol->maxArea(height1);
		cout << ret1 << endl;
		//Output : 49
		//Explanation : The above vertical lines are represented by array[1, 8, 6, 2, 5, 4, 8, 3, 7].In this case, the max area of water(blue section) the container can contain is 49.
		

		vector<int> height2 = { 1, 1 };
		int ret2 = sol->maxArea(height2);
		cout << ret2 << endl;
		//Output : 1
	}
};
