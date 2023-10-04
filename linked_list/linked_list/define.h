#pragma once

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
