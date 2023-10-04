#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

/*
    Design stack that supports push, pop, top, & retriving min element

    2 stacks, 1 normal & 1 monotonic decr, only push if lower than top

    Time: O(1)
    Space: O(n)
*/

class _0155_min_stack
{
public:
    _0155_min_stack() {

    }

    void push(int val) {
        stk.push(val);

        if (minStk.empty() || val < minStk.top().first) {
            minStk.push({ val, 1 });
        }
        else if (val == minStk.top().first) {
            minStk.top().second++;
        }
    }

    void pop() {
        if (stk.top() == minStk.top().first) {
            minStk.top().second--;
            if (minStk.top().second == 0) {
                minStk.pop();
            }
        }
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top().first;
    }

	void do_test(_0155_min_stack* sol)
	{

        sol->push(-2);
        sol->push(0);
        sol->push(-3);
        int ret1 = sol->getMin(); // return -3
        sol->pop();
        int ret2 = sol->top();    // return 0
        int ret3 = sol->getMin(); // return -2
        
        vector<string> res = { "null", "null", "null", to_string(ret1), 
            "null", to_string(ret2), to_string(ret3) };

        print_res(res);
	}

    void print_res(vector<string>& res)
    {
        cout << "[";
        for (unsigned int i = 0; i < res.size(); ++i)
        {
            cout << res[i] << ",";
        }
        cout << "]" << endl;
    }
private:
    stack<int> stk;
    stack<pair<int, int>> minStk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
