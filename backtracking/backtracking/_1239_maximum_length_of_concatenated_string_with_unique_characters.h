#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;


class _1239_maximum_length_of_concatenated_string_with_unique_characters
{
public:
    int maxLength(vector<string>& arr) {
        unordered_set<char> charSet;
        return backtrack(arr, charSet, 0);
    }
    
    int overlap(unordered_set<char>& a, string& b) {
        unordered_set<char> prev;
        for (char c: b) {
            if (a.find(c) != a.end() || prev.find(c) != prev.end()) {
                return true;
            }
            prev.insert(c);
        }
        return false;
    }

    int backtrack(vector<string>& arr, unordered_set<char>& charSet, int i) {
        if (i == arr.size()) {
            return charSet.size();
        }

        int res = 0;
        if (!overlap(charSet, arr[i])) {
            for (char c : arr[i]) {
                charSet.insert(c);
            }
            res = backtrack(arr, charSet, i + 1);
            for (char c : arr[i]) {
                charSet.erase(c);
            }
        }
        return max(res, backtrack(arr, charSet, i + 1));
    }

    /*
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<vector<int>> arr_st;
        for (int i = 0; i < n; i++) {
            string s = arr[i];
            vector<int> st(26);
            bool drop = false;
            for (char c : s) {
                st[c - 'a']++;
                if (st[c - 'a'] == 2) {
                    drop = true;
                }
            }
            if (!drop) {
                arr_st.push_back(st);
            }
        }

        int n2 = arr_st.size();
        vector<vector<int>> cache(n2, vector<int>(26));
        vector<int> cache2(n2);

        vector<int> result(26);
        int ans = 0;
        dfs(arr_st, 0, result, ans, cache, cache2);
        return ans;
    }

    void dfs(vector<vector<int>>& arr_st, int i, vector<int>& prev, int& ans, vector<vector<int>>& cache,
        vector<int>& cache2) {
        if (i >= arr_st.size()) {
            return;
        }

        if (cache[i] == prev && calculate_score(prev) > 0) {
            ans = max(ans, cache2[i]);
            return;
        }

        vector<int> curr = arr_st[i];
        vector<int> next(26);
        add_two_vector(prev, curr, next);
        ans = max(ans, calculate_score(next));
        dfs(arr_st, i + 1, next, ans, cache, cache2);
        cache[i] = prev;
        cache2[i] = ans;
        dfs(arr_st, i + 1, prev, ans, cache, cache2);
    }

    int calculate_score(vector<int>& vc) {
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += vc[i];
        }
        return ans;
    }

    void add_two_vector(vector<int>& prev, vector<int>& curr, vector<int>& next) {
        bool success = true;
        for (int i = 0; i < 26; i++) {
            if (prev[i] && curr[i]) {
                success = false;
                break;
            }
            if (prev[i] || curr[i])
                next[i] = 1;
            else {
                next[i] = 0;
            }
        }
        if (!success) {
            for (int i = 0; i < 26; i++) {
                next[i] = prev[i];
            }
        }
        return;
    }
    */
    

    void do_test(_1239_maximum_length_of_concatenated_string_with_unique_characters* sol) {
        vector<string> arr1 = { "un", "iq", "ue" };
        int ret1 = sol->maxLength(arr1);
        cout << ret1 << endl;
        // Output: 4

        vector<string> arr2 = { "cha", "r", "act", "ers" };
        int ret2 = sol->maxLength(arr2);
        cout << ret2 << endl;
        // Output: 6

        vector<string> arr3 = { "a", "abc", "d", "de", "def" };
        int ret3 = sol->maxLength(arr3);
        cout << ret3 << endl;
        // Output: 6

        vector<string> arr4 = { "aa", "bb" };
        int ret4 = sol->maxLength(arr4);
        cout << ret4 << endl;
        // Output: 0
	}
};
