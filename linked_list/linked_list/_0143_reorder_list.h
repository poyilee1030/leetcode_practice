#pragma once

#include <iostream>
#include "define.h"

using namespace std;

class _0143_reorder_list
{
public:
	ListNode* reorderList(ListNode* head) {
		if (head->next == NULL) {
			return NULL;
		}

		ListNode* prev = NULL;
		ListNode* slow = head;
		ListNode* fast = head;

		while (fast != NULL && fast->next != NULL) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		prev->next = NULL;

		ListNode* l1 = head;
		ListNode* l2 = reverse(slow);
		return merge(l1, l2);
	}

	ListNode* reverse(ListNode* head) {
		ListNode* prev = NULL;
		ListNode* curr = head;
		ListNode* next = curr->next;

		while (curr != NULL) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		return prev;
	}

	ListNode* merge(ListNode* l1, ListNode* l2) {
		ListNode* head = l1;
		while (l1 != NULL) {
			ListNode* p1 = l1->next;
			ListNode* p2 = l2->next;

			l1->next = l2;
			if (p1 == NULL) {
				break;
			}
			l2->next = p1;

			l1 = p1;
			l2 = p2;
		}
		return head;
	}

	void do_test(_0143_reorder_list* sol)
	{
		// case1
		ListNode* c1_node4 = new ListNode(4);
		ListNode* c1_node3 = new ListNode(3);
		c1_node3->next = c1_node4;
		ListNode* c1_node2 = new ListNode(2);
		c1_node2->next = c1_node3;
		ListNode* c1_node1 = new ListNode(1);
		c1_node1->next = c1_node2;

		ListNode* res1 = sol->reorderList(c1_node1);
		//Output: [1,4,2,3]
		print_res(res1);

		// case2
		ListNode* c2_node5 = new ListNode(5);
		ListNode* c2_node4 = new ListNode(4);
		c2_node4->next = c2_node5;
		ListNode* c2_node3 = new ListNode(3);
		c2_node3->next = c2_node4;
		ListNode* c2_node2 = new ListNode(2);
		c2_node2->next = c2_node3;
		ListNode* c2_node1 = new ListNode(1);
		c2_node1->next = c2_node2;

		ListNode* res2 = sol->reorderList(c2_node1);
		//Output: [1,5,2,4,3]
		print_res(res2);
	}

	void print_res(ListNode* res)
	{
		cout << "[";
		while (res)
		{
			cout << res->val << ",";
			res = res->next;
		}
		cout << "]" << endl;
	}
};
