#pragma once

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include "define.h"

using namespace std;

/*
Complexity Analysis
Let n be the number of nodes in the tree.

Time complexity: O(n)

    Converting the tree to a graph using a preorder traversal costs O(n). 
    We then perform BFS, which also costs O(n) because we don't visit a node more than once.

Space complexity: O(n)

    When converting the tree to a graph, we require O(n) extra space for the map. 
    We also require O(n) space for the queue and O(n) space for the visited set during the BFS.
*/

class _2385_amount_of_time_for_binary_tree_to_be_infected_bfs
{
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, unordered_set<int>> map;
        convert(root, 0, map);
        queue<int> q;
        q.push(start);
        int minute = 0;
        unordered_set<int> visited;
        visited.insert(start);

        while (!q.empty()) {
            int levelSize = q.size();
            while (levelSize > 0) {
                int current = q.front();
                q.pop();

                for (int num : map[current]) {
                    if (visited.find(num) == visited.end()) {
                        visited.insert(num);
                        q.push(num);
                    }
                }
                levelSize--;
            }
            minute++;
        }
        return minute - 1;
    }

    void convert(TreeNode* current, int parent, unordered_map<int, unordered_set<int>>& map) {
        if (current == nullptr) {
            return;
        }
        if (map.find(current->val) == map.end()) {
            map[current->val] = unordered_set<int>();
        }
        unordered_set<int>& adjacentList = map[current->val];
        if (parent != 0) {
            adjacentList.insert(parent);
        }
        if (current->left != nullptr) {
            adjacentList.insert(current->left->val);
        }
        if (current->right != nullptr) {
            adjacentList.insert(current->right->val);
        }
        convert(current->left, current->val, map);
        convert(current->right, current->val, map);
    }

	void do_test(_2385_amount_of_time_for_binary_tree_to_be_infected_bfs* sol) {
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
