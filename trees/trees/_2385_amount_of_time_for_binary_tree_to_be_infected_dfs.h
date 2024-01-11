#pragma once

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include "define.h"

using namespace std;

/*
Complexity
Let n be the number of nodes in the tree.

Time complexity: O(n)

    Traversing the tree with a DFS costs O(n) as we visit each node exactly once.

Space complexity: O(n)

    The space complexity of DFS is determined by the maximum depth of the call stack, 
    which corresponds to the depth of the tree (or the graph in our case). 
    In the worst case, if the tree is completely unbalanced (e.g., a linked list), 
    the call stack can grow as deep as the number of nodes, 
    resulting in a space complexity of O(n).
*/

class _2385_amount_of_time_for_binary_tree_to_be_infected_dfs
{
private:
    int maxDistance = 0;

public:
    int amountOfTime(TreeNode* root, int start) {
        dfs(root, start);
        return maxDistance;
    }

    int dfs(TreeNode* root, int start) {
        int depth = 0;
        if (root == nullptr) {
            return depth;
        }

        int leftDepth = dfs(root->left, start);
        int rightDepth = dfs(root->right, start);

        if (root->val == start) {
            maxDistance = max(leftDepth, rightDepth);
            depth = -1;
        }
        else if (leftDepth >= 0 && rightDepth >= 0) {
            depth = max(leftDepth, rightDepth) + 1;
        }
        else {
            int distance = abs(leftDepth) + abs(rightDepth);
            maxDistance = max(maxDistance, distance);
            depth = min(leftDepth, rightDepth) - 1;
        }

        return depth;
    }

    void do_test(_2385_amount_of_time_for_binary_tree_to_be_infected_dfs* sol) {
        TreeNode* c1r4_9 = new TreeNode(9);
        TreeNode* c1r4_2 = new TreeNode(2);
        TreeNode* c1r3_4 = new TreeNode(4, c1r4_9, c1r4_2);
        TreeNode* c1r3_10 = new TreeNode(10);
        TreeNode* c1r3_6 = new TreeNode(6);
        TreeNode* c1r2_5 = new TreeNode(5, NULL, c1r3_4);
        TreeNode* c1r2_3 = new TreeNode(3, c1r3_10, c1r3_6);
        TreeNode* c1r1_1 = new TreeNode(1, c1r2_5, c1r2_3);
        int ret1 = sol->amountOfTime(c1r1_1, 3);
        cout << ret1 << endl;
        /*
        Output : 4
        Explanation : The following nodes are infected during :
        - Minute 0 : Node 3
        - Minute 1 : Nodes 1, 10 and 6
        - Minute 2 : Node 5
        - Minute 3 : Node 4
        - Minute 4 : Nodes 9 and 2
        It takes 4 minutes for the whole tree to be infected so we return 4.
        */

        TreeNode* c2r1_1 = new TreeNode(1);
        int ret2 = sol->amountOfTime(c2r1_1, 1);
        cout << ret2 << endl;
        // Output : 0
        // Explanation : At minute 0, the only node in the tree is infected so we return 0.
    }
};
