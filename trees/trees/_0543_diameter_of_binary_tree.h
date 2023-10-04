#pragma once


#include <iostream>
#include "define.h"

using namespace std;



class _0543_diameter_of_binary_tree
{
public:
	int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
	}

	void do_test(_0543_diameter_of_binary_tree* sol)
	{
        TreeNode* t5 = new TreeNode(5);
        TreeNode* t4 = new TreeNode(4);
        TreeNode* t3 = new TreeNode(3);
        TreeNode* t2 = new TreeNode(2, t4, t5);
        TreeNode* t1 = new TreeNode(1, t2, t3);

        int res = sol->diameterOfBinaryTree(t1);
        cout << res << endl;

        TreeNode* nt2 = new TreeNode(2);
        TreeNode* nt1 = new TreeNode(1, nt2, NULL);
        int res2 = sol->diameterOfBinaryTree(nt1);
        cout << res2 << endl;
	}
private:
    int dfs(TreeNode* root, int& result)
    {
        if (root == NULL)
            return 0;

        int left = dfs(root->left, result);
        int right = dfs(root->right, result);

        result = max(result, left + right);
        return 1 + max(left, right);
    }
};


