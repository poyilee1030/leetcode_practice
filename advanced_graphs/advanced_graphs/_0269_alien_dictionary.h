#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class _0269_alien_dictionary
{
public:
	string alienOrder(vector<string>& words) {
		return "";
	}

	void do_test(_0269_alien_dictionary* sol)
	{
		vector<string> words1 = { "wrt", "wrf", "er", "ett", "rftt" };
		string ret1 = sol->alienOrder(words1);
		cout << ret1 << endl;
		// Output : "wertf"
		

		vector<string> words2 = { "z", "x" };
		string ret2 = sol->alienOrder(words2);
		cout << ret2 << endl;
		// Output : "zx"
		

		vector<string> words3 = { "z", "x", "z" };
		string ret3 = sol->alienOrder(words3);
		cout << ret3 << endl;
		// Output : ""
		// Explanation : The order is invalid, so return "".
	}
};
