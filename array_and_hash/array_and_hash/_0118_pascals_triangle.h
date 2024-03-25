#pragma once

#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;


class _0118_pascals_triangle
{
public:
	vector<vector<int>> generate(int numRows) {

		vector<vector<int>> result;
		for (int i = 1; i < numRows+1; i++) {
			if (i == 1)
				result.push_back({ 1 });
			else if(i == 2)
				result.push_back({ 1, 1 });
			else {
				vector<int> last_row = result[result.size() - 1];
				vector<int> new_row = { 1 };
				for (int j = 0; j < last_row.size() - 1; j++) {
					new_row.push_back(last_row[j] + last_row[j + 1]);
				}
				new_row.push_back(1);
				result.push_back(new_row);
			}
		}
		return result;
	}

	void do_test(_0118_pascals_triangle* sol)
	{
		int numRows1 = 5;
		vector<vector<int>> ret1 = sol->generate(numRows1);
		print_vector_of_vector(ret1);
		// Output : [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]
		
		int numRows2 = 1;
		vector<vector<int>> ret2 = sol->generate(numRows2);
		print_vector_of_vector(ret2);
		// Output : [[1]]
	}
};
