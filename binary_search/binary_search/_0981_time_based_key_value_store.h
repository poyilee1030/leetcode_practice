#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


class _0981_time_based_key_value_store
{
public:

    void set(string key, string value, int timestamp) {

    }

    string get(string key, int timestamp) {

    }

	void do_test(_0981_time_based_key_value_store* sol)
	{
        sol->set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
        string ret1 = sol->get("foo", 1);         // return "bar"
        ret1 = sol->get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
        cout << ret1 << endl;
        sol->set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
        ret1 = sol->get("foo", 4);         // return "bar2"
        cout << ret1 << endl;
        ret1 = sol->get("foo", 5);         // return "bar2"
        cout << ret1 << endl;
	}
};





