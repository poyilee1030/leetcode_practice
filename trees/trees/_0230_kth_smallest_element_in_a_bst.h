#pragma once

#include <iostream>
#include "define.h"

using namespace std;


class _0230_kth_smallest_element_in_a_bst
{
public:
	int kthSmallest(TreeNode* root, int k) {
		int result = 0;
		inorder(root, k, result);
		return result;
	}

	void inorder(TreeNode* root, int& k, int& result) {
		if (root == NULL) {
			return;
		}
		inorder(root->left, k, result);
		k--;
		if (k == 0) {
			result = root->val;
			return;
		}
		inorder(root->right, k, result);
	}

	void do_test(_0230_kth_smallest_element_in_a_bst* sol)
	{
		TreeNode* c1r3_2 = new TreeNode(2);
		TreeNode* c1r2_4 = new TreeNode(4);
		TreeNode* c1r2_1 = new TreeNode(1);
		TreeNode* c1r1_3 = new TreeNode(3, c1r2_1, c1r2_4);
		int res1 = kthSmallest(c1r1_3, 1);
		cout << res1 << endl;

		TreeNode* c2r4_1 = new TreeNode(1);
		TreeNode* c2r3_2 = new TreeNode(2, c2r4_1, NULL);
		TreeNode* c2r3_4 = new TreeNode(4);
		TreeNode* c2r2_3 = new TreeNode(3, c2r3_2, c2r3_4);
		TreeNode* c2r2_6 = new TreeNode(6);
		TreeNode* c2r1_5 = new TreeNode(5, c2r2_3, c2r2_6);
		int res2 = kthSmallest(c2r1_5, 3);
		cout << res2 << endl;
	}
};



