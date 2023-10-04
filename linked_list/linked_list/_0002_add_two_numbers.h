#pragma once

#include <iostream>
#include "define.h"

using namespace std;

class _0002_add_two_numbers
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();

        ListNode* curr = dummy;
        int carry = 0;

        while (l1 != NULL || l2 != NULL) {
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            if (l1 != NULL) {
                l1 = l1->next;
            }
            if (l2 != NULL) {
                l2 = l2->next;
            }
        }

        if (carry == 1) {
            curr->next = new ListNode(1);
        }

        return dummy->next;
	}

	void do_test(_0002_add_two_numbers* sol)
	{
        // case1
        ListNode* c1_1_node3 = new ListNode(3);
        ListNode* c1_1_node2 = new ListNode(4);
        c1_1_node2->next = c1_1_node3;
        ListNode* c1_1_node1 = new ListNode(2);
        c1_1_node1->next = c1_1_node2;

        ListNode* c1_2_node3 = new ListNode(4);
        ListNode* c1_2_node2 = new ListNode(6);
        c1_2_node2->next = c1_2_node3;
        ListNode* c1_2_node1 = new ListNode(5);
        c1_2_node1->next = c1_2_node2;

        ListNode* res1 = sol->addTwoNumbers(c1_1_node1, c1_2_node1);
        print_res(res1);

        // case2
        ListNode* c2_1_node1 = new ListNode(0);
        ListNode* c2_2_node1 = new ListNode(0);
        ListNode* res2 = sol->addTwoNumbers(c2_1_node1, c2_2_node1);
        print_res(res2);

        // case3
        ListNode* c3_1_node7 = new ListNode(9);
        ListNode* c3_1_node6 = new ListNode(9);
        c3_1_node6->next = c3_1_node7;
        ListNode* c3_1_node5 = new ListNode(9);
        c3_1_node5->next = c3_1_node6;
        ListNode* c3_1_node4 = new ListNode(9);
        c3_1_node4->next = c3_1_node5;
        ListNode* c3_1_node3 = new ListNode(9);
        c3_1_node3->next = c3_1_node4;
        ListNode* c3_1_node2 = new ListNode(9);
        c3_1_node2->next = c3_1_node3;
        ListNode* c3_1_node1 = new ListNode(9);
        c3_1_node1->next = c3_1_node2;

        ListNode* c3_2_node4 = new ListNode(9);
        ListNode* c3_2_node3 = new ListNode(9);
        c3_2_node3->next = c3_2_node4;
        ListNode* c3_2_node2 = new ListNode(9);
        c3_2_node2->next = c3_2_node3;
        ListNode* c3_2_node1 = new ListNode(9);
        c3_2_node1->next = c3_2_node2;

        ListNode* res3 = sol->addTwoNumbers(c3_1_node1, c3_2_node1);
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
