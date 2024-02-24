#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


void basic_unordered_set() {
	// unordered_set
	unordered_set<char> st = {'x'};

	st.insert('a');
	st.insert({ 'e', 'i', 'o', 'u'});
	st.erase('i');
	
	bool res = st.count('u');
	cout << "res = " << res << endl;

	if (st.find('e') != st.end()) {
		cout << "e existed." << endl;
	}

	// Convert Set To Vector in C++
	// way 1
	cout << "way 1 start" << endl;
	vector<char> vc(st.begin(), st.end());
	for (auto n: vc)
		cout << n << ", ";
	cout << endl << "way 1 end" << endl;

	// way 2
	cout << "way 2 start" << endl;
	vector<char> vc2;
	for (auto& it: st) {
		vc2.push_back(it);
	}
	for (auto n : vc2)
		cout << n << ", ";
	cout << endl << "way 2 end" << endl;

	// way 3
	cout << "way 3 start" << endl;
	vector<char> vc3(st.size());
	copy(st.begin(), st.end(), vc.begin());
	for (auto n : vc)
		cout << n << ", ";
	cout << endl << "way 3 end" << endl;
}
