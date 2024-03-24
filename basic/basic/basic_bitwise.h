#pragma once

#include <iostream>

using namespace std;

void bb_example1() {
	/*
	0xaaaaaaaa = 10101010101010101010101010101010 (案计1 计0)
	0x55555555 = 01010101010101010101010101010101 (案计0 计1)
	0x33333333 = 00110011001100110011001100110011 (0㎝1–筳ㄢユ蠢瞷)
	0xcccccccc = 11001100110011001100110011001100 (1㎝0–筳ㄢユ蠢瞷)
	0x0f0f0f0f = 00001111000011110000111100001111 (0㎝1–筳ユ蠢瞷)
	0xf0f0f0f0 = 11110000111100001111000011110000 (1㎝0–筳ユ蠢瞷)
	*/
	int a = 3;
	int b = 3;
	int c = a & b;
	cout << "c = " << c << endl;

	int e = 1;
	int f = 2;
	int g = 3;
}

void basic_bitwise()
{
	bb_example1();
}
