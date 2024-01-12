#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


void basic_unordered_set() {
	// unordered_set
	unordered_set<char> set;

	set.insert('a');
	set.insert({ 'e', 'i', 'o', 'u'});
	set.erase('i');
	
	bool res = set.count('u');
	cout << "res = " << res << endl;

	if (set.find('e') != set.end()) {
		cout << "e existed." << endl;
	}

	

}
