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
        tmap[key].push_back({ timestamp, value });
    }

    string get(string key, int timestamp) {
        if (tmap.find(key) == tmap.end()) {
            return "";
        }
        if (timestamp < tmap[key][0].first) {
            return "";
        }
        int n = tmap[key].size();
        int l = 0;
        int r = n - 1;
        // 1 4 5 7  target= 5
        while (l < r) {
            int mid = r - (r - l) / 2;
            if (tmap[key][mid].first <= timestamp) {
                l = mid;
            }
            else if (tmap[key][mid].first > timestamp) {
                r = mid - 1;
            }
            // else {
            //     return tmap[key][mid].second;
            // }
        }

        if (l >= 0) {
            return tmap[key][l].second;
        }
        return "";
    }

	void do_test(_0981_time_based_key_value_store* sol)
	{
        string ret;

        sol->set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
        ret = sol->get("foo", 1);         // return "bar"
        ret = sol->get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
        cout << ret << endl;
        sol->set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
        ret = sol->get("foo", 4);         // return "bar2"
        cout << ret << endl;
        ret = sol->get("foo", 5);         // return "bar2"
        cout << ret << endl;
	}
private:
    unordered_map<string, vector<pair<int, string>>> tmap;
};





