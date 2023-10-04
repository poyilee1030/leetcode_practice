#pragma once

#include <iostream>
#include "define.h"

using namespace std;


class _0572_subtree_of_another_tree
{
public:
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if (subRoot == NULL)
			return true;
		if (root == NULL)
			return false;

		if (isSameTree(root, subRoot))
			return true;

		bool left = isSubtree(root->left, subRoot);
		bool right = isSubtree(root->right, subRoot);
		if (left || right)
			return true;
		else
			return false;
	}

	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL)
			return true;
		if (p == NULL && q != NULL)
			return false;
		if (p != NULL && q == NULL)
			return false;

		if (p->val != q->val)
			return false;

		bool left = isSameTree(p->left, q->left);
		bool right = isSameTree(p->right, q->right);

		if (left && right)
			return true;
		else
			return false;
	}

	void do_test(_0572_subtree_of_another_tree* sol)
	{
		TreeNode* c1r2 = new TreeNode(2);
		TreeNode* c1r1 = new TreeNode(1);
		TreeNode* c1r5 = new TreeNode(5);
		TreeNode* c1r4 = new TreeNode(4, c1r1, c1r2);
		TreeNode* c1r3 = new TreeNode(3, c1r4, c1r5);

		TreeNode* c1s1 = new TreeNode(1);
		TreeNode* c1s2 = new TreeNode(2);
		TreeNode* c1s4 = new TreeNode(4, c1s1, c1s2);
		
		bool res1 = isSubtree(c1r3, c1s4);
		cout << res1 << endl;

		TreeNode* c2r0 = new TreeNode(0);
		TreeNode* c2r2 = new TreeNode(2, c2r0, NULL);
		TreeNode* c2r1 = new TreeNode(1);
		TreeNode* c2r5 = new TreeNode(5);
		TreeNode* c2r4 = new TreeNode(4, c2r1, c2r2);
		TreeNode* c2r3 = new TreeNode(3, c2r4, c2r5);

		TreeNode* c2s1 = new TreeNode(1);
		TreeNode* c2s2 = new TreeNode(2);
		TreeNode* c2s4 = new TreeNode(4, c2s1, c2s2);

		bool res2 = isSubtree(c2r3, c2s4);
		cout << res2 << endl;
	}
};

