#pragma once

#include <iostream>
#include <unordered_map>
#include "define.h"

using namespace std;

class _0138_copy_list_with_random_pointer
{
public:
	Node* copyRandomList(Node* head) {
		unordered_map<Node*, Node*> nodes;
		Node* h = head;

		while (h) {
			nodes[h] = new Node(h->val);
			h = h->next;
		}
		h = head;
		while (h) {
			Node* newNode = nodes[h];
			newNode->next = nodes[h->next];
			newNode->random = nodes[h->random];
			h = h->next;
		}
		return nodes[head];
	}

	void do_test(_0138_copy_list_with_random_pointer* sol)
	{
		Node* c1node5 = new Node(1);
		Node* c1node4 = new Node(10);
		Node* c1node3 = new Node(11);
		Node* c1node2 = new Node(13);
		Node* c1node1 = new Node(7);

		c1node1->next = c1node2;
		c1node2->next = c1node3;
		c1node3->next = c1node4;
		c1node4->next = c1node5;

		c1node2->random = c1node1;
		c1node3->random = c1node5;
		c1node4->random = c1node3;
		c1node5->random = c1node1;

		print_res(c1node1);
		Node *res = sol->copyRandomList(c1node1);
		print_res(res);
	}

	void print_res(Node* res)
	{
		cout << "[";
		while (res)
		{
			cout << "[";
			cout << res->val << ",";
			if (res->random == NULL)
			{
				cout << "null";
			}
			else
			{
				cout << res->random;
			}
			cout << "],";
			res = res->next;
		}
		cout << "]" << endl;
	}
};


