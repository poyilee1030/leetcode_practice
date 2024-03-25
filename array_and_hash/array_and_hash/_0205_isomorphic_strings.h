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
        string s1 = "egg";
        string t1 = "add";
        bool ret1 = sol->isIsomorphic(s1, t1);
        cout << ret1 << endl;
        // Output : true
        
        string s2 = "foo";
        string t2 = "bar";
        bool ret2 = sol->isIsomorphic(s2, t2);
        cout << ret2 << endl;
        // Output : false
        
        string s3 = "paper";
        string t3 = "title";
        bool ret3 = sol->isIsomorphic(s3, t3);
        cout << ret3 << endl;
        // Output : true

        string s4 = "12";
        string t4 = "\u0067\u0067";
        bool ret4 = sol->isIsomorphic(s4, t4);
        cout << ret4 << endl;
        // Output : true
	}
};
