#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class _0202_happy_number
{
public:
	bool isHappy(int n) {
		unordered_set<int> s;

		while (s.find(n) == s.end()) {
			s.insert(n);
			n = sumOfSquare(n);
			if (n == 1) {
				return true;
			}
		}
		return false;
	}

	int sumOfSquare(int n) {
		int output = 0;
		while (n) {
			int a = n % 10;
			a = a * a;
			output += a;
			n = int(n / 10);
		}
		return output;
	}

	void do_test(_0202_happy_number* sol) {
		int n1 = 19;
		bool ret1 = sol->isHappy(n1);
		cout << ret1 << endl;
		/*
		Output : true
		Explanation :
		1^2 + 9^2 = 82
		8^2 + 2^2 = 68
		6^2 + 8^2 = 100
		1^2 + 0^2 + 0^2 = 1
		*/

		int n2 = 2;
		bool ret2 = sol->isHappy(n2);
		cout << ret2 << endl;
		// Output : false
	}
};
