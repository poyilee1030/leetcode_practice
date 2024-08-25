#pragma once

#include <iostream>
#include <vector>
#include "define.h"

using namespace std;


class _0095_unique_binary_search_trees_ii
{
public:
    vector<TreeNode*> generateTrees(int n)
    {
        if (n == 0) 
            return {};

        return generateTreesDFS(1, n);
    }

    vector<TreeNode*> generateTreesDFS(int start, int end)
    {
        vector<TreeNode*> subTree;
        if (start > end) {
            subTree.push_back(NULL);
        }
        else {
            for (int i = start; i <= end; i++) {
                vector<TreeNode*> leftSubTree = generateTreesDFS(start, i - 1);
                vector<TreeNode*> rightSubTree = generateTreesDFS(i + 1, end);

                for (int j = 0; j < leftSubTree.size(); ++j) {
                    for (int k = 0; k < rightSubTree.size(); ++k) {
                        TreeNode* node = new TreeNode(i);
                        node->left = leftSubTree[j];
                        node->right = rightSubTree[k];
                        subTree.push_back(node);
                    }
                }
            }
        }

        return subTree;
    }

    void do_test(_0095_unique_binary_search_trees_ii* sol) {
        vector<TreeNode*> res;

        res = generateTrees(3);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i]->val << ",";
        }
    }
};
