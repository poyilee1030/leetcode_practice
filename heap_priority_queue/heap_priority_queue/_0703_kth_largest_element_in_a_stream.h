#pragma once

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class KthLargest
{
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        while (pq.size() > this->k) {
            pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
};


class _0703_kth_largest_element_in_a_stream
{
public:
	void do_test(_0703_kth_largest_element_in_a_stream* sol)
	{
        int k = 3;
        vector<int> nums = { 4, 5, 8, 2 };
        KthLargest obj = KthLargest(k, nums);

        // return 4
        int res1 = obj.add(3);
        cout << res1 << endl;

        // return 5
        int res2 = obj.add(5);
        cout << res2 << endl;

        // return 5
        int res3 = obj.add(10);
        cout << res3 << endl;
        
        // return 8
        int res4 = obj.add(9);
        cout << res4 << endl;
        
        // return 8
        int res5 = obj.add(4);
        cout << res5 << endl;
	}
};
