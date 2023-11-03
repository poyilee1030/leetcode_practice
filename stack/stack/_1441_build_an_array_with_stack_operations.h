#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


class _1441_build_an_array_with_stack_operations
{
public:
	vector<string> buildArray(vector<int>& target, int n) {
		vector<string> r;
		stack<int> s;
		int t_idx = 0;
		for (int i = 1; i < n+1; i++) {
			s.push(i);
			r.push_back("Push");

			int top = s.top();
			if (target[t_idx] == top) {
				t_idx++;
			}
			else {
				s.pop();
				r.push_back("Pop");
			}

			if (t_idx >= target.size())
				break;
		}
		return r;
	}

	void do_test(_1441_build_an_array_with_stack_operations* sol) {
		vector<int> target1 = { 1, 3 };
		vector<string> ret1 = sol->buildArray(target1, 3);
		print_res(ret1);
		/*
		Output : ["Push", "Push", "Pop", "Push"]
		Explanation : Initially the stack s is empty.The last element is the top of the stack.
		Read 1 from the stream and push it to the stack.s = [1].
		Read 2 from the stream and push it to the stack.s = [1, 2].
		Pop the integer on the top of the stack.s = [1].
		Read 3 from the stream and push it to the stack.s = [1, 3].
		*/

		vector<int> target2 = { 1, 2, 3 };
		vector<string> ret2 = sol->buildArray(target2, 3);
		print_res(ret2);
		/*
		Output : ["Push", "Push", "Push"]
		Explanation : Initially the stack s is empty.The last element is the top of the stack.
		Read 1 from the stream and push it to the stack.s = [1].
		Read 2 from the stream and push it to the stack.s = [1, 2].
		Read 3 from the stream and push it to the stack.s = [1, 2, 3].
		*/


		vector<int> target3 = { 1, 2 };
		vector<string> ret3 = sol->buildArray(target3, 4);
		print_res(ret3);
		/*
		Output : ["Push", "Push"]
		Explanation : Initially the stack s is empty.The last element is the top of the stack.
		Read 1 from the stream and push it to the stack.s = [1].
		Read 2 from the stream and push it to the stack.s = [1, 2].
		Since the stack(from the bottom to the top) is equal to target, we stop the stack operations.
		The answers that read integer 3 from the stream are not accepted.
		*/

	}

	void print_res(vector<string> res) {
		cout << "[";
		for (int i = 0; i < res.size();i++) {
			cout << res[i];
			if (i < res.size() - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}
};
