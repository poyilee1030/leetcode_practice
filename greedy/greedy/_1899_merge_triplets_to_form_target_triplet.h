#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _1899_merge_triplets_to_form_target_triplet
{
public:
	bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
		return false;
	}

	void do_test(_1899_merge_triplets_to_form_target_triplet* sol) {
		vector<vector<int>> triplets1 = { {2, 5, 3}, {1, 8, 4}, {1, 7, 5} };
		vector<int> target1 = { 2, 7, 5 };
		bool ret1 = sol->mergeTriplets(triplets1, target1);
		cout << ret1 << endl;
		/*
		Output : true
		Explanation : Perform the following operations :
		- Choose the first and last triplets {{2, 5, 3}, {1, 8, 4}, {1, 7, 5}} .
		Update the last triplet to be[max(2, 1), max(5, 7), max(3, 5)] = [2, 7, 5].
		triplets = {{2, 5, 3}, {1, 8, 4}, {2, 7, 5}}
		The target triplet[2, 7, 5] is now an element of triplets.
		*/
		
		vector<vector<int>> triplets2 = { {3, 4, 5}, {4, 5, 6} };
		vector<int> target2 = { 3, 2, 5 };
		bool ret2 = sol->mergeTriplets(triplets2, target2);
		cout << ret2 << endl;
		/*
		Output : false
		Explanation : It is impossible to have[3, 2, 5] as an element because 
					  there is no 2 in any of the triplets.
		*/
		
		vector<vector<int>> triplets3 = { {2, 5, 3}, {2, 3, 4}, {1, 2, 5}, {5, 2, 3} };
		vector<int> target3 = { 5, 5, 5 };
		bool ret3 = sol->mergeTriplets(triplets3, target3);
		cout << ret3 << endl;
		/*
		Output : true
		Explanation : Perform the following operations :
		- Choose the first and third triplets {{2, 5, 3}, {2, 3, 4}, {1, 2, 5}, {5, 2, 3}} .
		Update the third triplet to be[max(2, 1), max(5, 2), max(3, 5)] = [2, 5, 5].
		triplets = {{2, 5, 3}, {2, 3, 4}, {2, 5, 5}, {5, 2, 3}} .

		- Choose the third and fourth triplets {{2, 5, 3}, {2, 3, 4}, {2, 5, 5}, {5, 2, 3}} .
		Update the fourth triplet to be[max(2, 5), max(5, 2), max(5, 3)] = [5, 5, 5].
		triplets = {{2, 5, 3}, {2, 3, 4}, {2, 5, 5}, {5, 5, 5}} .
		The target triplet[5, 5, 5] is now an element of triplets.
		*/
	}
};
