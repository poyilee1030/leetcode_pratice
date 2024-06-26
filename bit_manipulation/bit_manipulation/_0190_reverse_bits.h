#pragma once

#include <iostream>

using namespace std;


class _0190_reverse_bits
{
public:
	uint32_t reverseBits(uint32_t n) {
		int res = 0;
		for (int i = 0; i < 32; i++) {
			int bit = (n >> i) & 1;
			res = res | (bit << (31-i));
		}
		return res;
	}

	void do_test(_0190_reverse_bits* sol)
	{
		string s;
		uint32_t n;
		uint32_t ret;

		s = "00000010100101000001111010011100";
		n = convert_string_to_uint32(s);
		ret = sol->reverseBits(n);
		cout << ret << endl;
		/*
		Output : 964176192 (00111001011110000010100101000000)
		Explanation : The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596,
					  so return 964176192 which its binary representation is 00111001011110000010100101000000.
		*/

		s = "11111111111111111111111111111101";
		n = convert_string_to_uint32(s);
		ret = sol->reverseBits(n);
		cout << ret << endl;
		/*
		Output : 3221225471 (10111111111111111111111111111111)
		Explanation : The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, 
		              so return 3221225471 which its binary representation is 10111111111111111111111111111111.
		*/
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
