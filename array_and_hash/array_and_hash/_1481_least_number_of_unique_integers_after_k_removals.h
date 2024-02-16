#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;


class _1481_least_number_of_unique_integers_after_k_removals
{
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> count;
        for (int n : arr) {
            count[n]++;
        }

        if (k == 0) {
            return count.size();
        }

        map<int, vector<int>> freq;
        for (auto it : count) {
            freq[it.second].push_back(it.first);
        }

        for (auto it = freq.begin(); it != freq.end(); it++) {
            while (!it->second.empty() && k > 0) {
                it->second.pop_back();
                k = k - it->first;
            }
            if (k <= 0)
                break;
        }
        /*
        // 如果沒用「&」實際上它會複製一份，所以pop_back會影響不到原來的那個vector
        for (auto& it : freq) {
            while (!it.second.empty() && k > 0) {
                it.second.pop_back();
                k = k - it.first;
            }
            if (k <= 0)
                break;
        }
        */

        int ans = 0;
        for (auto it : freq) {
            ans += it.second.size();
        }

        return (k < 0) ? (ans + 1) : ans;
    }

	void do_test(_1481_least_number_of_unique_integers_after_k_removals* sol) {
        vector<int> arr1 = { 5, 5, 4 };
        int res1 = sol->findLeastNumOfUniqueInts(arr1, 1);
        cout << res1 << endl;
        // Output : 1
        // Explanation : Remove the single 4, only 5 is left.
        
        vector<int> arr2 = { 4, 3, 1, 1, 3, 3, 2 };
        int res2 = sol->findLeastNumOfUniqueInts(arr2, 3);
        cout << res2 << endl;
        // Output : 2
        // Explanation : Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.

        vector<int> arr3 = { 2, 4, 1, 8, 3, 5, 1, 3 };
        int res3 = sol->findLeastNumOfUniqueInts(arr3, 3);
        cout << res3 << endl;
        // Output : 3
	}

};
