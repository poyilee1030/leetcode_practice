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


void basic_vector() {
    
    // --------- 1d vector ��l�� ---------
    vector<int> b = { 1, 2, 3, 4, 5, 19, 11, 7};
    print_vector(b);

    // �b vector ��Y�Ӥ���
    if (find(b.begin(), b.end(), 4) != b.end())
        cout << "found!" << endl;

    // �b vector ��Y�Ӥ����� idx
    auto itx = find(b.begin(), b.end(), 4);
    if (itx == b.end()) {
        // name not in vector
    }
    else {
        // way1: c++11����i�H�ϥ� distance
        int index1 = distance(b.begin(), itx);
        cout << "the index1 = " << index1 << endl;

        // way2: c++11�H�e���g�k
        int index2 = find(b.begin(), b.end(), 4) - b.begin();
        cout << "the index2 = " << index2 << endl;
    }

    // assign �ɡA��ڤW�O�ƻs�F�@���A����� a ���Ab �]�����v�T
    vector<int> a = b;
    a[5] = 18;
    print_vector(a);


    vector<int> c(5, 1); //(size, value)
    print_vector(c);

    vector<int> d(3); //(size, value default is 0)
    print_vector(d);


    // �� vector ���̤j����m (�H vector b ����)
    int max_idx = max_element(b.begin(), b.end()) - b.begin();
    cout << "max_idx = " << max_idx << endl;

    // �� vector ���̤j���� (�H vector b ����) �g�k1
    vector<int>::iterator it;
    it = max_element(b.begin(), b.end());
    cout << "max value (style 1) = " << *it << endl;

    // �� vector ���̤j���� (�H vector b ����) �g�k2
    cout << "max value (style 2) = " << *max_element(b.begin(), b.end()) << endl;


    // merge 1d vector
    vector<int> A = { 2, 3, 4, 5 };
    vector<int> B = { 6, 7, 8, 9 };
    vector<int> AB = A;
    AB.insert(AB.end(), B.begin(), B.end());
    print_vector(AB);



    // --------- 2d vector ��l�� ---------
    int row_count = 3;
    int col_count = 5;
    // value default is 0
    vector<vector<int>> fog1(row_count, vector<int>(col_count));

    // value default is 4
    vector<vector<int>> fog2(row_count, vector<int>(col_count, 4));


    vector<vector<int>> ans;
    vector<int> curr = { 3, 5, 7 };
    // push_back �ɡA��ڤW�O�ƻs�F�@���A����� curr ���Aans �]�����v�T
    cout << "##############" << endl;
    ans.push_back(curr);
    print_vector_of_vector(ans);
    curr[1] = 4;
    cout << "after change some element in curr" << endl;
    print_vector_of_vector(ans);
    
}
