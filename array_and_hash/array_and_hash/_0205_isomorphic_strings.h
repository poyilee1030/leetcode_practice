#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class _0205_isomorphic_strings
{
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, vector<int>>m1;
        unordered_map<char, vector<int>>m2;
        for (int i = 0; i < s.length(); i++) {
            m1[s[i]].push_back(i);
            m2[t[i]].push_back(i);

            if (m1[s[i]] != m2[t[i]])
                return false;
        }
        return true;
    }

	void do_test(_0205_isomorphic_strings* sol) {
        bool ret;

        ret = sol->isIsomorphic("egg", "add");
        cout << ret << endl;
        // Output : true
        
        ret = sol->isIsomorphic("foo", "bar");
        cout << ret << endl;
        // Output : false
        
        ret = sol->isIsomorphic("paper", "title");
        cout << ret << endl;
        // Output : true

        ret = sol->isIsomorphic("12", "\u0067\u0067");
        cout << ret << endl;
        // Output : true
	}
};
