#pragma once

#include <iostream>
#include <vector>
#include "define.h"

using namespace std;


class _0105_construct_binary_tree_from_preorder_and_inorder_traversal
{
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int index = 0;
		return build(preorder, inorder, index, 0, inorder.size() - 1);
	}

	TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& index, int i, int j) {
		if (i > j) {
			return NULL;
		}

		TreeNode* root = new TreeNode(preorder[index]);

		int split = 0;
		for (int i = 0; i < inorder.size(); i++) {
			if (preorder[index] == inorder[i]) {
				split = i;
				break;
			}
		}
		index++;

		root->left = build(preorder, inorder, index, i, split - 1);
		root->right = build(preorder, inorder, index, split + 1, j);

		return root;
	}

	void do_test(_0105_construct_binary_tree_from_preorder_and_inorder_traversal* sol)
	{
		vector<int> p1 = { 3, 9, 20, 15, 7 };
		vector<int> i1 = { 9, 3, 15, 20, 7 };
		TreeNode* res1 = buildTree(p1, i1);
		print_tree("", res1, false);

		vector<int> p2 = { -1 };
		vector<int> i2 = { -1 };
		TreeNode* res2 = buildTree(p2, i2);
		print_tree("", res2, false);
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


