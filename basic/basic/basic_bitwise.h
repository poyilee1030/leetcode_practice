#pragma once

#include <iostream>

using namespace std;

void bb_example1() {
	/*
	0xaaaaaaaa = 10101010101010101010101010101010 (���Ʀ쬰1�A �_�Ʀ쬰0)
	0x55555555 = 01010101010101010101010101010101 (���Ʀ쬰0�A �_�Ʀ쬰1)
	0x33333333 = 00110011001100110011001100110011 (0�M1�C�j������X�{)
	0xcccccccc = 11001100110011001100110011001100 (1�M0�C�j������X�{)
	0x0f0f0f0f = 00001111000011110000111100001111 (0�M1�C�j�|�����X�{)
	0xf0f0f0f0 = 11110000111100001111000011110000 (1�M0�C�j�|�����X�{)
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
