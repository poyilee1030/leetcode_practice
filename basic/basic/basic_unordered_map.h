#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;


void basic_unordered_map() {
    // unordered_map
    unordered_map<char, int> udmap;
    udmap['a'] = 1;
    udmap['b'] = 2;
    udmap['c'] = 3;
    udmap['d'] = 4;
    udmap['e'] = 5;

    if (udmap.find('f') != udmap.end()) {
        cout << "exist f" << endl;
    }
    else {
        cout << "not exist f" << endl;
    }

    udmap.erase('a');

    auto it0 = udmap.begin();
    cout << "begin of map, " << it0->first << ": " << it0->second << endl;

    // 如何遍歷一個 unordered_map
    cout << "way 1" << endl;
    for (auto it1: udmap) {
        cout << it1.first << ": " << it1.second << endl;
    }

    cout << "way 2" << endl;
    for (auto it2 = udmap.begin(); it2 != udmap.end(); it2++) {
        cout << it2->first << ": " << it2->second << endl;
    }

    cout << "way 3" << endl;
    unordered_map<char, int>::iterator it3 = udmap.begin();
    while (it3 != udmap.end()) {
        int count = it3->second;
        cout << it3->first << ": " << it3->second << endl;
        it3++;
    }
    // ------------------------

    // map             可以用 pair<int, int> 當作 key
    // unordered_map 不可以用 pair<int, int> 當作 key
    // to do: why only map can use pair as key
    map<pair<int, int>, string> myMap;

    myMap[{1, 2}] = "Hello";
    myMap[{3, 4}] = "World";

    if (myMap.find({ 1, 2 }) != myMap.end())
        cout << "{1, 2} exist in map" << endl;

    // to do: const 和 & 在此有何功用?
    for (const auto& entry : myMap) {
        cout << "(" << entry.first.first << ", " << entry.first.second << "): " << entry.second << endl;
    }
}
