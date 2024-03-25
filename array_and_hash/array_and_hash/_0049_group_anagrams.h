#pragma once

#include <string>
#include <vector>
#include <array>

using namespace std;


class _0049_group_anagrams
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> m;
        for (unsigned int i = 0; i < strs.size(); i++) {
            string key = getKey(strs[i]);
            m[key].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for (auto it = m.begin(); it != m.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }

    string getKey(string str)
    {
        /* 
        解答原本的寫法，但有人說不建議用 pointer 的方式操作 vector
        vector<int> count(26);
        for (int j = 0; j < str.size(); j++) {
            count[str[j] - 'a']++;
        }
        */
        
        array<int, 26> count = {};
        for (unsigned int j = 0; j < str.size(); j++) {
            count[str[j] - 'a']++;
        }

        string key = "";
        for (unsigned int i = 0; i < count.size(); i++) {
            key.append(to_string(count[i]) + '#');
        }
        return key;
    }

    void do_test(_0049_group_anagrams* sol)
    {
        vector<string> strs;
        vector<vector<string>> ret;

        strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
        ret = sol->groupAnagrams(strs);
        print_vector_of_vector(ret);

        strs = { "" };
        ret = sol->groupAnagrams(strs);
        print_vector_of_vector(ret);

        strs = { "a" };
        ret = sol->groupAnagrams(strs);
        print_vector_of_vector(ret);
    }
};
