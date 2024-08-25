#pragma once

#include <iostream>
#include <vector>
#include "define.h"
#include "utils.h"

using namespace std;


class _0199_binary_tree_right_side_view
{
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
			return result;

		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			int count = q.size();
			for (int i = 0; i < count; i++)
			{
				TreeNode* node = q.front();
				q.pop();

				if (i == count - 1)
					result.push_back(node->val);

				if (node->left != NULL)
					q.push(node->left);
				if (node->right != NULL)
					q.push(node->right);
			}
		}
		return result;
	}

	void do_test(_0199_binary_tree_right_side_view* sol) {
		vector<int> res;

		TreeNode* c1r5 = new TreeNode(5);
		TreeNode* c1r4 = new TreeNode(4);
		TreeNode* c1r2 = new TreeNode(2, NULL, c1r5);
		TreeNode* c1r3 = new TreeNode(3, NULL, c1r4);
		TreeNode* c1r1 = new TreeNode(1, c1r2, c1r3);

		res = rightSideView(c1r1);
		print_vector(res);
		// Output: [1, 3, 4]

		TreeNode* c2r3 = new TreeNode(3);
		TreeNode* c2r1 = new TreeNode(1, NULL, c2r3);
		res = rightSideView(c2r1);
		print_vector(res);
		// Output: [1, 3]

		res = rightSideView(NULL);
		print_vector(res);
		// Output: []
	}
};
