#pragma once

#include <iostream>
#include "define.h"

using namespace std;


class _0110_balanced_binary_tree
{
public:
	bool isBalanced(TreeNode* root) {
		bool isBalanced = true;
		dfs(root, isBalanced);
		return isBalanced;
	}

	void do_test(_0110_balanced_binary_tree* sol)
	{
		TreeNode* c1t15 = new TreeNode(15);
		TreeNode* c1t7 = new TreeNode(7);
		TreeNode* c1t20 = new TreeNode(20, c1t15, c1t7);
		TreeNode* c1t9 = new TreeNode(9);
		TreeNode* c1t3 = new TreeNode(3, c1t9, c1t20);

		bool res1 = sol->isBalanced(c1t3);
		cout << res1 << endl;

		TreeNode* c2t4b = new TreeNode(4);
		TreeNode* c2t4a = new TreeNode(4);
		TreeNode* c2t3b = new TreeNode(3);
		TreeNode* c2t3a = new TreeNode(3, c2t4a, c2t4b);
		TreeNode* c2t2b = new TreeNode(2);
		TreeNode* c2t2a = new TreeNode(2, c2t3a, c2t3b);
		TreeNode* c2t1 = new TreeNode(1, c2t2a, c2t2b);

		bool res2 = sol->isBalanced(c2t1);
		cout << res2 << endl;

		TreeNode* c3 = NULL;
		bool res3 = sol->isBalanced(c3);
		cout << res3 << endl;
	}
private:
	int dfs(TreeNode* root, bool& isBalanced)
	{
		if (root == NULL)
			return 0;

		int left = dfs(root->left, isBalanced);
		int right = dfs(root->right, isBalanced);

		if (isBalanced && abs(left - right) <= 1)
		{
			
		}
		else
		{
			isBalanced = false;
		}

		return 1 + max(left, right);
	}
};


