#pragma once

#include <iostream>
#include <vector>

using namespace std;


class _1160_find_words_that_can_be_formed_by_characters
{
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> arr(26, 0);
        for (auto c : chars) {
            arr[c - 'a']++;
        }

        int result = 0;
        for (string word : words) {
            vector<int> tmp(26, 0);
            for (auto c : word) {
                tmp[c - 'a']++;
            }

            if (is_good(arr, tmp)) {
                result += word.size();
            }
        }
        return result;
    }

    bool is_good(vector<int>& arr, vector<int>& tmp) {
        for (int i = 0; i < 26; i++) {
            if ((arr[i] - tmp[i]) < 0) {
                return false;
            }
        }
        return true;
    }

	void do_test(_1160_find_words_that_can_be_formed_by_characters* sol) {
        vector<string> words1 = { "cat", "bt", "hat", "tree" };
        string chars1 = "atach";
        int ret1 = sol->countCharacters(words1, chars1);
        cout << ret1 << endl;
        // Output : 6
        // Explanation : The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.


        vector<string> words2 = { "hello", "world", "leetcode" };
        string chars2 = "welldonehoneyr";
        int ret2 = sol->countCharacters(words2, chars2);
        cout << ret2 << endl;
        // Output : 10
        // Explanation : The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
	}
};



