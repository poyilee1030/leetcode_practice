#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;


void basic_unordered_map() {
    // unordered_map
    unordered_map<char, int> map;
    map['a'] = 1;
    map['b'] = 2;
    map['c'] = 3;
    map['d'] = 4;
    map['e'] = 5;

    map.erase('a');

    auto it0 = map.begin();
    cout << "begin of map, " << it0->first << ": " << it0->second << endl;

    cout << "way 1" << endl;
    for (auto& it1 : map) {
        cout << it1.first << ": " << it1.second << endl;
    }

    cout << "way 2" << endl;
    for (auto i = map.begin(); i != map.end(); i++) {
        cout << i->first << ": " << i->second << endl;
    }

    cout << "way 3" << endl;
    unordered_map<char, int>::iterator it2 = map.begin();
    while (it2 != map.end()) {
        int count = it2->second;
        cout << it2->first << ": " << it2->second << endl;
        it2++;
    }
}
