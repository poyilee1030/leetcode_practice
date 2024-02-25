#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;


class _2092_find_all_people_with_secret
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
    }

	void do_test(_2092_find_all_people_with_secret* sol) {
        vector<vector<int>> meetings1 = { {1, 2, 5}, {2, 3, 8}, {1, 5, 10} };
        vector<int> ret1 = sol->findAllPeople(6, meetings1, 1);
        print_vector(ret1);
        // Output: [0, 1, 2, 3, 5]

        vector<vector<int>> meetings2 = { {3, 1, 3}, {1, 2, 2}, {0, 3, 3} };
        vector<int> ret2 = sol->findAllPeople(4, meetings2, 3);
        print_vector(ret2);
        // Output: [0, 1, 3]

        vector<vector<int>> meetings3 = { {3, 4, 2}, {1, 2, 1}, {2, 3, 1} };
        vector<int> ret3 = sol->findAllPeople(5, meetings3, 1);
        print_vector(ret3);
        // Output: [0, 1, 2, 3, 4]

        vector<vector<int>> meetings4 = { {0, 2, 1}, {1, 3, 1}, {4, 5, 1} };
        vector<int> ret4 = sol->findAllPeople(6, meetings4, 1);
        print_vector(ret4);
        // Output: [0, 1, 2, 3]
	}

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
};
