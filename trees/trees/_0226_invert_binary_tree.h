#pragma once

#include <iostream>
#include "define.h"

using namespace std;

class _0226_invert_binary_tree
{
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

	void do_test(_0226_invert_binary_tree* sol)
	{
        TreeNode* t1 = new TreeNode(1);
        TreeNode* t3 = new TreeNode(3);
        TreeNode* t6 = new TreeNode(6);
        TreeNode* t9 = new TreeNode(9);
        TreeNode* t2 = new TreeNode(2, t1, t3);
        TreeNode* t7 = new TreeNode(7, t6, t9);
        TreeNode* t4 = new TreeNode(4, t2, t7);

        TreeNode *invert_t4 = sol->invertTree(t4);
        print_tree("", invert_t4, false);
	}

    void print_tree(const string& prefix, const TreeNode* node, bool isLeft)
    {
        if (node != nullptr)
        {
            cout << prefix;
            cout << (isLeft ? "¢u¢w¢w " : "¢|¢w¢w ");

            // print the value of the node
            cout << node->val << endl;

            // enter the next tree level - left and right branch
            print_tree(prefix + (isLeft ? "¢x   " : "    "), node->left, true);
            print_tree(prefix + (isLeft ? "¢x   " : "    "), node->right, false);
        }
    }
};





