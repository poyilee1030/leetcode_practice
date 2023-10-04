#pragma once

#include <iostream>
#include "define.h"

using namespace std;


class _0100_same_tree
{
public:
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

	void do_test(_0100_same_tree* sol)
	{
		TreeNode* q3 = new TreeNode(3);
		TreeNode* q2 = new TreeNode(2);
		TreeNode* q1 = new TreeNode(1, q2, q3);
		TreeNode* p3 = new TreeNode(3);
		TreeNode* p2 = new TreeNode(2);
		TreeNode* p1 = new TreeNode(1, p2, p3);
		bool res1 = isSameTree(p1, q1);
		cout << res1 << endl;

		TreeNode* c2q2 = new TreeNode(2);
		TreeNode* c2q1 = new TreeNode(1, NULL, c2q2);
		TreeNode* c2p2 = new TreeNode(2);
		TreeNode* c2p1 = new TreeNode(1, c2p2, NULL);
		bool res2 = isSameTree(c2p1, c2q1);
		cout << res2 << endl;
	}
};


