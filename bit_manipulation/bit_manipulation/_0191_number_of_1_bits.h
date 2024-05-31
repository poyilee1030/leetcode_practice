#pragma once

#include <iostream>

using namespace std;


class _0191_number_of_1_bits
{
public:
	int hammingWeight(uint32_t n) {
		int bit = 0;
		int result = 0;

		while (n != 0) {
			bit = n & 1;
			if (bit == 1) {
				result++;
			}
			n = n >> 1;
		}

		return result;
	}

	void do_test(_0191_number_of_1_bits* sol) {
		string s;
		uint32_t n;
		int ret;

		s = "00000000000000000000000000001011";
		n = convert_string_to_uint32(s);
		ret = sol->hammingWeight(n);
		cout << ret << endl;
		// Output : 3
		// Explanation : The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
		
		s = "00000000000000000000000010000000";
		n = convert_string_to_uint32(s);
		ret = sol->hammingWeight(n);
		cout << ret << endl;
		// Output : 1
		// Explanation : The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
		
		s = "11111111111111111111111111111101";
		n = convert_string_to_uint32(s);
		ret = sol->hammingWeight(n);
		cout << ret << endl;
		// Output : 31
		// Explanation : The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
	}

	uint32_t convert_string_to_uint32(string& s) {
		uint32_t result = 0;
		for (int i = 31; i >= 0; i--) {
			int p = 31 - i;
			int tmp = (s[p] - '0');
			uint32_t oo = tmp << i;
			result += oo;
		}
		return result;
	}
};
