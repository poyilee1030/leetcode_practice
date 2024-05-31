#pragma once

#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;


class _0989_add_to_array_form_of_integer
{
public:
	vector<int> addToArrayForm(vector<int>& num, int k) {

	}

	void do_test(_0989_add_to_array_form_of_integer* sol) {
		vector<int> num1 = { 1, 2, 0, 0 };
		int k1 = 34;
		vector<int> ret1 = sol->addToArrayForm(num1, k1);
		print_vector(ret1);
		// Output : [1, 2, 3, 4]
		// Explanation : 1200 + 34 = 1234


		vector<int> num2 = { 2, 7, 4 };
		int k2 = 181;
		vector<int> ret2 = sol->addToArrayForm(num2, k2);
		print_vector(ret2);
		// Output : [4, 5, 5]
		// Explanation : 274 + 181 = 455


		vector<int> num3 = { 2, 1, 5 };
		int k3 = 806;
		vector<int> ret3 = sol->addToArrayForm(num3, k3);
		print_vector(ret3);
		// Output : [1, 0, 2, 1]
		// Explanation : 215 + 806 = 1021
	}
};
