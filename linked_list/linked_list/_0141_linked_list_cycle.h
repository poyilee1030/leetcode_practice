#pragma once

#include <iostream>
#include "define.h"

using namespace std;

class _0141_linked_list_cycle
{
public:
	bool hasCycle(ListNode* head) {
        if (head == NULL) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }

        return false;
	}

	void do_test(_0141_linked_list_cycle* sol)
	{
        // case1
        ListNode* c1node4 = new ListNode(-4);
        ListNode* c1node3 = new ListNode(0);
        c1node3->next = c1node4;
        ListNode* c1node2 = new ListNode(2);
        c1node2->next = c1node3;
        ListNode* c1node1 = new ListNode(3);
        c1node1->next = c1node2;
        c1node4->next = c1node2;

        bool res1 = sol->hasCycle(c1node1);
        cout << res1 << endl;

        //case2
        ListNode* c2node2 = new ListNode(2);
        ListNode* c2node1 = new ListNode(1);
        c2node1->next = c2node2;
        c2node2->next = c2node1;

        bool res2 = sol->hasCycle(c2node1);
        cout << res2 << endl;

        //case3
        ListNode* c3node1 = new ListNode(1);
        bool res3 = sol->hasCycle(c3node1);
        cout << res3 << endl;
	}
};
