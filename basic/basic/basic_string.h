#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;


void basic_string_operate() {
    // string
    // string to int
    string ss = "123";
    int aa = stoi(ss);
    // int to string
    int bb = 456;
    string tt = to_string(bb);

    string ssss = "123456789";
    
    int l = 0;
    int wsize = 3;
    while (l < ssss.size()-wsize+1) {
        string ssss_sub = ssss.substr(l, wsize); // (start_pos, length)
        cout << ssss_sub << endl;
        l++;
    }
    
    // 當 length 比較長的時候，用 for loop 逐次疊加效率很差
    // to init a string with length and char
    int L = 10;
    char C = 'B';
    string tmp1(L, C);
    cout << "tmp1 = " << tmp1 << endl;

    string tmp2;
    tmp2.append(L, C);
    cout << "tmp2 = " << tmp2 << endl;

}
