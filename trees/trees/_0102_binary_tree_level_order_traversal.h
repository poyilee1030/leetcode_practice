#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include "define.h"

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

	void do_test(_0102_binary_tree_level_order_traversal* sol)
	{
		TreeNode* c1r7 = new TreeNode(7);
		TreeNode* c1r15 = new TreeNode(15);
		TreeNode* c1r20 = new TreeNode(20, c1r15, c1r7);
		TreeNode* c1r9 = new TreeNode(9);
		TreeNode* c1r3 = new TreeNode(3, c1r9, c1r20);

		vector<vector<int>> res1 = levelOrder(c1r3);
		print_res(res1);

		TreeNode* c2r = new TreeNode(1);
		vector<vector<int>> res2 = levelOrder(c2r);
		print_res(res2);
		
		vector<vector<int>> res3 = levelOrder(NULL);
		print_res(res3);
	}

	void print_res(vector<vector<int>>& res)
	{
		cout << "[";
		for (int i = 0; i < res.size(); ++i)
		{
			cout << "[";
			vector<int> oo = res[i];
			for (int j = 0; j < oo.size(); ++j)
			{
				cout << oo[j];
				if (j < oo.size() - 1)
					cout << ",";
			}
			cout << "]";
			if (i < res.size() - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}
};

