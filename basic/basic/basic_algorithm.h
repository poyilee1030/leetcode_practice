#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


template <typename T>
void print_vector(vector<T> v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}


void basic_algorithm() {

	vector<char> v = { 'b', 'a', 'A', 'B', '1', '0', '2'};
    sort(v.begin(), v.end(), greater<>());
    print_vector(v);
    sort(v.begin(), v.end());
    print_vector(v);
}
