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

void example1() {
    vector<char> v = { 'b', 'a', 'A', 'B', '1', '0', '2' };
    sort(v.begin(), v.end(), greater<>());
    print_vector(v);
    sort(v.begin(), v.end());
    print_vector(v);
}

void example2() {
    vector<vector<int>> vec = { {3, 1, 3},{1, 2, 2},{0, 3, 3} };

    sort(vec.begin(), vec.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

    print_vector_of_vector(vec);
}

static bool cmp(vector<int>& a, vector<int>& b)
{
    return a[2] < b[2];
}

void example3() {
    vector<vector<int>> vec = { {3, 1, 3},{1, 2, 2},{0, 3, 3} };

    sort(vec.begin(), vec.end(), cmp);

    print_vector_of_vector(vec);
}

void basic_algorithm() {
    //example1();
    //example2();
    example3();
}
