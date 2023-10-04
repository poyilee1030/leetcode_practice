#pragma once

#include <iostream>
#include "define.h"

using namespace std;


class _0098_validate_binary_search_tree
{
public:
	bool isValidBST(TreeNode* root) {
		return helper(root, LONG_MIN, LONG_MAX);
	}

	bool helper(TreeNode* root, long left, long right) {
		if (!root)
			return true;
		if (root->val < right && root->val > left) {
			return helper(root->left, left, root->val) && helper(root->right, root->val, right);
		}
		return false;
	}

	void do_test(_0098_validate_binary_search_tree* sol)
	{
		TreeNode* c1r2_1 = new TreeNode(1);
		TreeNode* c1r2_3 = new TreeNode(3);
		TreeNode* c1r1_2 = new TreeNode(2, c1r2_1, c1r2_3);
		bool res1 = isValidBST(c1r1_2);
		cout << res1 << endl;

		TreeNode* c2r3_3 = new TreeNode(3);
		TreeNode* c2r3_6 = new TreeNode(6);
		TreeNode* c2r2_1 = new TreeNode(1);
		TreeNode* c2r2_4 = new TreeNode(4, c2r3_3, c2r3_6);
		TreeNode* c2r1_5 = new TreeNode(5, c2r2_1, c2r2_4);
		bool res2 = isValidBST(c2r1_5);
		cout << res2 << endl;

		TreeNode* c3r3_3 = new TreeNode(3);
		TreeNode* c3r3_7 = new TreeNode(7);
		TreeNode* c3r2_6 = new TreeNode(6, c3r3_3, c3r3_7);
		TreeNode* c3r2_4 = new TreeNode(4);
		TreeNode* c3r1_5 = new TreeNode(5, c3r2_4, c3r2_6);
		bool res3 = isValidBST(c3r1_5);
		cout << res3 << endl;
	}
};





