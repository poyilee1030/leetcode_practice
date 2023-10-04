#pragma once

#include <iostream>
#include "define.h"

using namespace std;

class _0019_remove_nth_node_from_end_of_list
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return NULL;

        if (head->next == NULL && n == 1)
            return NULL;

        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = head;
        while (n > 0)
        {
            fast = fast->next;
            n -= 1;
        }

        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return dummy->next;
	}

	void do_test(_0019_remove_nth_node_from_end_of_list *sol)
	{
        // case1
        ListNode* c1node5 = new ListNode(5);
        ListNode* c1node4 = new ListNode(4);
        c1node4->next = c1node5;
        ListNode* c1node3 = new ListNode(3);
        c1node3->next = c1node4;
        ListNode* c1node2 = new ListNode(2);
        c1node2->next = c1node3;
        ListNode* c1node1 = new ListNode(1);
        c1node1->next = c1node2;

        ListNode* res1 = sol->removeNthFromEnd(c1node1, 2);
        print_res(res1);

        //case2
        ListNode* c2node1 = new ListNode(1);

        ListNode* res2 = sol->removeNthFromEnd(c2node1, 1);
        print_res(res2);

        //case3
        ListNode* c3node2 = new ListNode(2);
        ListNode* c3node1 = new ListNode(1);
        c3node1->next = c3node2;

        ListNode* res3 = sol->removeNthFromEnd(c3node1, 2);
        print_res(res3);
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


