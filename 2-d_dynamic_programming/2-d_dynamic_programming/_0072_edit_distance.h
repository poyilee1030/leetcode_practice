#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class _0072_edit_distance
{
public:
	int minDistance(string word1, string word2) {
		return 0;
	}

	void do_test(_0072_edit_distance *sol) {
		string word_11 = "horse";
		string word_12 = "ros";
		int ret1 = minDistance(word_11, word_12);
		cout << ret1 << endl;
		/*
		Output : 3
		Explanation :
		horse->rorse(replace 'h' with 'r')
		rorse->rose(remove 'r')
		rose->ros(remove 'e')
		*/
		
		
		string word_21 = "intention";
		string word_22 = "execution";
		int ret2 = minDistance(word_21, word_22);
		cout << ret2 << endl;
		/*
		Output : 5
		Explanation :
		intention->inention(remove 't')
		inention->enention(replace 'i' with 'e')
		enention->exention(replace 'n' with 'x')
		exention->exection(replace 'n' with 'c')
		exection->execution(insert 'u')
		*/
		
	}
};
