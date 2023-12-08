#pragma once

#include <iostream>
#include "define.h"

using namespace std;

class _0206_reverse_linked_list
{
public:
    // iterative
    /*
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL)
        {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
    */
    
    // recursive
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }

        ListNode* newHead = reverseList_internal(head, head->next);
        head->next = NULL;
        return newHead;
    }

    ListNode* reverseList_internal(ListNode* prev, ListNode* curr) {
        if (curr == NULL) {
            return prev;
        }

        ListNode *newHead = reverseList_internal(curr, curr->next);
        curr->next = prev;
        return newHead;
    }

	void do_test(_0206_reverse_linked_list *sol)
	{
        // case1
        ListNode *c1node5 = new ListNode(5);
        ListNode* c1node4 = new ListNode(4);
        c1node4->next = c1node5;
        ListNode* c1node3 = new ListNode(3);
        c1node3->next = c1node4;
        ListNode* c1node2 = new ListNode(2);
        c1node2->next = c1node3;
        ListNode* c1node1 = new ListNode(1);
        c1node1->next = c1node2;
        ListNode *res1 = sol->reverseList(c1node1);
        print_res(res1);

        // case2
        ListNode* c2node2 = new ListNode(2);
        ListNode* c2node1 = new ListNode(1);
        c2node1->next = c2node2;
        ListNode* res2 = sol->reverseList(c2node1);
        print_res(res2);

        // case3
        ListNode* res3 = sol->reverseList(NULL);
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





