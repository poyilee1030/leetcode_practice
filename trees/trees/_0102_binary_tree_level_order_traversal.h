#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include "define.h"
#include "utils.h"

using namespace std;


class _0102_binary_tree_level_order_traversal
{
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (root == NULL)
			return result;

		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			int count = q.size();
			vector<int> curr;

			for (int i = 0; i < count; i++)
			{
				TreeNode* node = q.front();
				q.pop();

				curr.push_back(node->val);
				
				if (node->left != NULL)
					q.push(node->left);
				if (node->right != NULL)
					q.push(node->right);
			}
			result.push_back(curr);
		}
		return result;
	}

	void do_test(_0102_binary_tree_level_order_traversal* sol) {
		vector<vector<int>> res;
		
		TreeNode* c1r7 = new TreeNode(7);
		TreeNode* c1r15 = new TreeNode(15);
		TreeNode* c1r20 = new TreeNode(20, c1r15, c1r7);
		TreeNode* c1r9 = new TreeNode(9);
		TreeNode* c1r3 = new TreeNode(3, c1r9, c1r20);

		res = levelOrder(c1r3);
		print_vector_of_vector(res);
		// Output: [[3], [9,20], [15,7]]

		TreeNode* c2r = new TreeNode(1);
		res = levelOrder(c2r);
		print_vector_of_vector(res);
		// Output: [[1]]
		
		res = levelOrder(NULL);
		print_vector_of_vector(res);
		// Output: []
	}
};
