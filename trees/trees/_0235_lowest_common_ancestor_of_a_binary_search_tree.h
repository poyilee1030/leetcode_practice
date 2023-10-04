#pragma once

#include <iostream>
#include "define.h"

using namespace std;


class _0235_lowest_common_ancestor_of_a_binary_search_tree
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (p->val < root->val && q->val < root->val) {
			return lowestCommonAncestor(root->left, p, q);
		}
		else if (p->val > root->val && q->val > root->val) {
			return lowestCommonAncestor(root->right, p, q);
		}
		else {
			return root;
		}
	}

	void do_test(_0235_lowest_common_ancestor_of_a_binary_search_tree* sol)
	{
		TreeNode* c1r3 = new TreeNode(3);
		TreeNode* c1r5 = new TreeNode(5);
		TreeNode* c1r0 = new TreeNode(0);
		TreeNode* c1r4 = new TreeNode(4, c1r3, c1r5);
		TreeNode* c1r7 = new TreeNode(7);
		TreeNode* c1r9 = new TreeNode(9);
		TreeNode* c1r2 = new TreeNode(2, c1r0, c1r4);
		TreeNode* c1r8 = new TreeNode(8, c1r7, c1r9);
		TreeNode* c1r6 = new TreeNode(6, c1r2, c1r8);

		TreeNode* c1p = new TreeNode(2);
		TreeNode* c1q = new TreeNode(8);

		TreeNode* res1 = lowestCommonAncestor(c1r6, c1p, c1q);
		cout << res1->val << endl;

		TreeNode* c2p = new TreeNode(2);
		TreeNode* c2q = new TreeNode(4);
		TreeNode* res2 = lowestCommonAncestor(c1r6, c2p, c2q);
		cout << res2->val << endl;
	}
};

