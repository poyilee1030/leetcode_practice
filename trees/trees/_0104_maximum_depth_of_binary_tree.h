#pragma once

#include <iostream>
#include "define.h"

using namespace std;


class _0104_maximum_depth_of_binary_tree
{
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + max(left, right);
    }

	void do_test(_0104_maximum_depth_of_binary_tree* sol) {
        int res;

        TreeNode* t15 = new TreeNode(15);
        TreeNode* t7 = new TreeNode(7);
        TreeNode* t9 = new TreeNode(9);
        TreeNode* t20 = new TreeNode(20, t15, t7);
        TreeNode* t3 = new TreeNode(3, t9, t20);
        res = sol->maxDepth(t3);
        cout << res << endl;
        // Output: 3

        TreeNode* t2 = new TreeNode(2);
        TreeNode* t1 = new TreeNode(1, NULL, t2);
        res = sol->maxDepth(t1);
        cout << res << endl;
        // Output: 2
	}
};
