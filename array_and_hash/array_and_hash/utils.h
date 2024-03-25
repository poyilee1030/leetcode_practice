#pragma once

#include <iostream>
#include <vector>

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

template <typename T>
void print_vector_of_vector(vector<vector<T>> v) {
    cout << "[";
    for (auto j = 0; j < v.size(); j++) {
        cout << "[";
        vector<T> vt = v[j];
        for (int i = 0; i < vt.size(); i++) {
            cout << vt[i];
            if (i < vt.size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (j < v.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}
