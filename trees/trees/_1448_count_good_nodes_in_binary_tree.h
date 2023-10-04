#pragma once

#include <iostream>
#include "define.h"

using namespace std;


class _1448_count_good_nodes_in_binary_tree
{
public:
    int goodNodes(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = subGoodNodes(root->left, root->val);
        int right = subGoodNodes(root->right, root->val);

        return left + right + 1;
    }

    int subGoodNodes(TreeNode* root, int max_val)
    {
        if (root == NULL)
            return 0;

        int good = 1;
        if (root->val < max_val)
            good = 0;

        max_val = max(max_val, root->val);

        int left = subGoodNodes(root->left, max_val);
        int right = subGoodNodes(root->right, max_val);

        return left + right + good;
    }

    void do_test(_1448_count_good_nodes_in_binary_tree* sol)
    {
        TreeNode* c1r3_3 = new TreeNode(3);
        TreeNode* c1r3_1 = new TreeNode(1);
        TreeNode* c1r3_5 = new TreeNode(5);
        TreeNode* c1r2_1 = new TreeNode(1, c1r3_3, NULL);
        TreeNode* c1r2_4 = new TreeNode(4, c1r3_1, c1r3_5);
        TreeNode* c1r1_3 = new TreeNode(3, c1r2_1, c1r2_4);
        int res1 = goodNodes(c1r1_3);
        cout << res1 << endl;

        TreeNode* c2r3_4 = new TreeNode(4);
        TreeNode* c2r3_2 = new TreeNode(2);
        TreeNode* c2r2_3 = new TreeNode(3, c2r3_4, c2r3_2);
        TreeNode* c2r1_3 = new TreeNode(3, c2r2_3, NULL);
        int res2 = goodNodes(c2r1_3);
        cout << res2 << endl;

        TreeNode* c3r1_1 = new TreeNode(1);
        int res3 = goodNodes(c3r1_1);
        cout << res3 << endl;
    }
};


