#pragma once

#include <iostream>
#include "define.h"

using namespace std;


class _2265_count_nodes_equal_to_average_of_subtree
{
public:
	int averageOfSubtree(TreeNode* root) {
		int sum = 0;
		int count = 0;
		int result = 0;
		dfs(root, sum, count, result);
		return result;
	}

	void dfs(TreeNode* node, int& sum, int& count, int& result) {
		if (node == NULL) {
			return;
		}

		int leftsum = 0;
		int leftcount = 0;
		dfs(node->left, leftsum, leftcount, result);

		int rightsum = 0;
		int rightcount = 0;
		dfs(node->right, rightsum, rightcount, result);

		count = leftcount + rightcount + 1;
		sum = leftsum + rightsum + node->val;
		int average = sum / count;
		if (average == node->val) {
			result += 1;
		}
	}

	void do_test(_2265_count_nodes_equal_to_average_of_subtree* sol) {
		TreeNode* c1r34 = new TreeNode(6);
		TreeNode* c1r32 = new TreeNode(1);
		TreeNode* c1r31 = new TreeNode(0);
		TreeNode *c1r22 = new TreeNode(5, NULL, c1r34);
		TreeNode *c1r21 = new TreeNode(8, c1r31, c1r32);
		TreeNode *c1r11 = new TreeNode(4, c1r21, c1r22);
		int ret1 = sol->averageOfSubtree(c1r11);
		cout << ret1 << endl;
		/*
		Output : 5
		Explanation :
		For the node with value 4 : The average of its subtree is(4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
		For the node with value 5 : The average of its subtree is(5 + 6) / 2 = 11 / 2 = 5.
		For the node with value 0 : The average of its subtree is 0 / 1 = 0.
		For the node with value 1 : The average of its subtree is 1 / 1 = 1.
		For the node with value 6 : The average of its subtree is 6 / 1 = 6.
		*/
		
		TreeNode *c2r1 = new TreeNode(1);
		int ret2 = sol->averageOfSubtree(c2r1);
		cout << ret2 << endl;
		/*
		Output : 1
		Explanation : For the node with value 1 : The average of its subtree is 1 / 1 = 1.
		*/
	}
};
