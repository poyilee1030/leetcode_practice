#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class _1442_count_triplets_that_can_form_two_arrays_of_equal_xor
{
public:
	int countTriplets(vector<int>& arr) {
		unordered_map<int, vector<int>> Map; // pre_xor_sum_val -> {idx}
		Map[0].push_back({ -1 });

		int xorsum = 0;
		int ret = 0;
		for (int k = 0; k < arr.size(); k++) {
			xorsum ^= arr[k];
			for (int i : Map[xorsum]) {
				// xorsum [i+1:k] == 0
				// j: i+2 -> k
				ret += k - i - 1; // 其實是 k-(i+2)+1 解開括號
			}
			Map[xorsum].push_back(k);
		}
		return ret;
	}
	
	/*
	影片10:55的地方
	xor_sum[i:k] = pre_xor_sum[k] ^ pre_xor_sum[i-1]

	左右交換
	pre_xor_sum[k] ^ pre_xor_sum[i-1] = xor_sum[i:k]

	一起取pre_xor_sum[k]^
	pre_xor_sum[k] ^ pre_xor_sum[k] ^ pre_xor_sum[i-1] = pre_xor_sum[k] ^ xor_sum[i:k]
	 ↑ 一樣的東西取^ 會變成0 ↑ 

	上式變成↓，同時我們希望 xor_sum[i:k] 這項是 0
	pre_xor_sum[i-1] = pre_xor_sum[k] ^ xor_sum[i:k]

	所以變成
	pre_xor_sum[i-1] = pre_xor_sum[k] ^ 0;
	*/

	void do_test(_1442_count_triplets_that_can_form_two_arrays_of_equal_xor* sol) {
		vector<int> arr;
		int res;

		arr = { 2, 3, 1, 6, 7 };
		res = sol->countTriplets(arr);
		cout << res << endl;
		// Output : 4
		
		arr = { 1, 1, 1, 1, 1 };
		res = sol->countTriplets(arr);
		cout << res << endl;
		// Output : 10
	}
};
