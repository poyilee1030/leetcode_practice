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

    vector<int> b = { 1, 2, 3, 4, 5, 19, 11, 7};
    print_vector(b);

    vector<int> c(5, 1); //(size, value)
    print_vector(c);

    vector<int> d(3); //(size, value default is 0)
    print_vector(d);

    // 找 vector 中最大的位置 (以 vector b 為例)
    int max_idx = max_element(b.begin(), b.end()) - b.begin();
    cout << "max_idx = " << max_idx << endl;

    // 找 vector 中最大的位置 (以 vector b 為例) 寫法1
    vector<int>::iterator it;
    it = max_element(b.begin(), b.end());
    cout << "max value (style 1) = " << *it << endl;

    // 找 vector 中最大的位置 (以 vector b 為例) 寫法2
    cout << "max value (style 2) = " << *max_element(b.begin(), b.end()) << endl;

    // --------- 2d vector ---------
    int row_count = 3;
    int col_count = 5;
    // value default is 0
    vector<vector<int>> fog1(row_count, vector<int>(col_count));

    // value default is 4
    vector<vector<int>> fog2(row_count, vector<int>(col_count, 4));
}
