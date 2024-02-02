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
    
}
