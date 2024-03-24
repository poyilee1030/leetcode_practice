#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "basic_vector.h"

using namespace std;


void algo_example1() {
    vector<char> v = { 'b', 'a', 'A', 'B', '1', '0', '2' };
    sort(v.begin(), v.end(), greater<>());
    print_vector(v);
    sort(v.begin(), v.end());
    print_vector(v);
}

void algo_example2() {
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

void algo_example3() {
    vector<vector<int>> vec = { {3, 1, 3},{1, 2, 2},{0, 3, 3} };

    sort(vec.begin(), vec.end(), cmp);

    print_vector_of_vector(vec);
}

class XYZ {
    int custom_idx[26];
public:
    XYZ() {
        // 自定義字母 a-z 排序順序
        // 故意將 a, b 的順序顛倒，其他不變
        for (int i = 0; i < 26; i++)
            custom_idx[i] = i;

        custom_idx[0] = 1;
        custom_idx[1] = 0;
    }
    
    void do_sort_test() {
        string str = "xyzab";

        sort(str.begin(), str.end());
        // output: abxyz
        cout << "original sort: " << str << endl;
                                     // ↓加了 this 可以使用 member variable: custom_idx
        sort(str.begin(), str.end(), [this](const char& m, const char& n) {
                return custom_idx[m - 'a'] < custom_idx[n - 'a'];
            });
        // output: baxyz
        cout << "custom sort: " << str << endl;
    }
};

void algo_example4() {
    cout << "example4::" << endl;
    XYZ* xyz = new XYZ();
    xyz->do_sort_test();
}

void algo_example5() {
    cout << "example5::" << endl;
    int custom_idx[26];
    // 自定義字母 a-z 排序順序
    // 故意將 a, b 的順序顛倒，其他不變
    for (int i = 0; i < 26; i++)
        custom_idx[i] = i;

    custom_idx[0] = 1;
    custom_idx[1] = 0;

    string str = "xyzab";

    sort(str.begin(), str.end());
    // output: abxyz
    cout << "original sort: " << str << endl;
                               // ↓加了 & 可以使用外面的 local variable: custom_idx
    sort(str.begin(), str.end(), [&](const char& m, const char& n) {
            return custom_idx[m - 'a'] < custom_idx[n - 'a'];
        });
    // output: baxyz
    cout << "custom sort: " << str << endl;
}

void basic_algorithm() {
    //algo_example1();
    //algo_example2();
    //algo_example3();
    //algo_example4();
    algo_example5();
}
