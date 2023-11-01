#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include "define.h"

using namespace std;


class _0501_find_mode_in_binary_search_tree
{
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> m;
        dfs(root, m);

        int maxFreq = 0;
        vector<int> ans;
        
        // iterator
        unordered_map<int, int>::iterator it;
        for (it = m.begin(); it != m.end(); it++) {
            maxFreq = max(maxFreq, it->second);
        }

        for (it = m.begin(); it != m.end(); it++) {
            if (it->second == maxFreq)
                ans.push_back(it->first);
        }

        /* c++11
        for (auto const& x : m) {
            maxFreq = max(maxFreq, x.second);
        }

        for (auto const& x : m) {
            if (x.second == maxFreq)
                ans.push_back(x.first);
        }
        */
        

        /* c++17
        for (auto& [key, val] : m) {
            maxFreq = max(maxFreq, val);
        }

        
        for (auto& [key, val] : m) {
            if (val == maxFreq) {
                ans.push_back(key);
            }
        }
        */

        return ans;
    }

    void dfs(TreeNode* node, unordered_map<int, int>& m) {

        if (node == NULL)
            return;

        m[node->val] += 1;

        dfs(node->left, m);
        dfs(node->right, m);
    }

	void do_test(_0501_find_mode_in_binary_search_tree* sol) {

        TreeNode* c1r3 = new TreeNode(2, NULL, NULL);
        TreeNode* c1r2 = new TreeNode(2, c1r3, NULL);
        TreeNode* c1r1 = new TreeNode(1, NULL, c1r2);
        vector<int> ret1 = sol->findMode(c1r1);
        print_res(ret1);
        // Output : [2]
        
        TreeNode * c2r1 = new TreeNode(0, NULL, NULL);
        vector<int> ret2 = sol->findMode(c2r1);
        print_res(ret2);

        // Output : [0]
	}

    void print_res(vector<int>& res)
    {
        cout << "[";
        for (int i = 0; i < res.size(); ++i)
        {
            cout << res[i];
            if (i < res.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }
};
