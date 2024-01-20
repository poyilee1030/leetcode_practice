#pragma once

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class _0907_sum_of_subarray_minimums
{
public:
    int sumSubarrayMins(vector<int>& arr)
    {
        int n = arr.size();
        vector<int>nextSmaller(n, n);
        vector<int>prevSmaller(n, -1);

        stack<int>Stack;
        for (int i = 0; i < n; i++)
        {
            while (!Stack.empty() && arr[Stack.top()] > arr[i])
            {
                nextSmaller[Stack.top()] = i;
                Stack.pop();
            }

            if (!Stack.empty())
                prevSmaller[i] = Stack.top();
            Stack.push(i);
        }


        long ret = 0;
        long M = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            int a = prevSmaller[i];
            int b = nextSmaller[i];
            long num = arr[i] * (i - a) % M * (b - i) % M;
            ret = (ret + num) % M;
        }
        return ret;
    }

	void do_test(_0907_sum_of_subarray_minimums* sol) {
        vector<int> arr1 = { 3, 1, 2, 4 };
        int ret1 = sol->sumSubarrayMins(arr1);
        cout << ret1 << endl;
        /*
        Output : 17
        Explanation :
        Subarrays are[3], [1], [2], [4], [3, 1], [1, 2], [2, 4], [3, 1, 2], [1, 2, 4], [3, 1, 2, 4].
        Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
        Sum is 17.
        */

        vector<int> arr2 = { 11, 81, 94, 43, 3 };
        int ret2 = sol->sumSubarrayMins(arr2);
        cout << ret2 << endl;
        // Output : 444

        vector<int> arr3 = { 81, 55, 2};
        int ret3 = sol->sumSubarrayMins(arr3);
        cout << ret3 << endl;
        // Output : 197
	}
};
