#pragma once

#include <iostream>
#include <vector>

using namespace std;


void print_vector(vector<int> v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}


void basic_vector() {
    // vector
    // declare a vector
    vector<int> a;

    vector<int> b = { 1, 2, 3, 4, 5 };
    print_vector(b);

    vector<int> c(5, 1); //(size, value)
    print_vector(c);

    vector<int> d(3); //(size, value default is 0)
    print_vector(d);
}
