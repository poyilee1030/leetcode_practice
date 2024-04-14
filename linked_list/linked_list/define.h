#pragma once

#include <iostream>
#include <vector>

using namespace std;


struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr)
	{
	}
	ListNode(int x) : val(x), next(nullptr)
	{
	}
	ListNode(int x, ListNode* next) : val(x), next(next)
	{
	}
};

void print_ListNode(ListNode* node)
{
	cout << "[";
	while (node)
	{
		cout << node->val << ", ";
		node = node->next;
	}
	cout << "]" << endl;
}

ListNode* create_ListNodes_from_vector(vector<int> nums)
{
	vector<ListNode*> nodes;
	for (int i = 0; i < nums.size(); i++) {
		nodes.push_back(new ListNode(nums[i]));
	}

	ListNode* p = nodes[0];
	for (int i = 0; i < nums.size()-1; i++) {
		nodes[i]->next = nodes[i + 1];
	}
	
	return nodes[0];
}


class Node
{
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};


class Node2 {
public:
	int k;
	int val;
	Node2* prev;
	Node2* next;

	Node2(int key, int value) {
		k = key;
		val = value;
		prev = NULL;
		next = NULL;
	}
};
