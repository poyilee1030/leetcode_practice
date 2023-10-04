#pragma once

#include <iostream>
#include "define.h"

using namespace std;

class _0021_merge_two_sorted_lists
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL && list2 == NULL) {
            return NULL;
        }
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val <= list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        if (list1 != NULL) {
            curr->next = list1;
        }
        else if (list2 != NULL) {
            curr->next = list2;
        }

        return dummy->next;
    }

	void do_test(_0021_merge_two_sorted_lists* sol)
	{
        // case1
        ListNode* c1_1_node3 = new ListNode(4);
        ListNode* c1_1_node2 = new ListNode(2);
        c1_1_node2->next = c1_1_node3;
        ListNode* c1_1_node1 = new ListNode(1);
        c1_1_node1->next = c1_1_node2;

        ListNode* c1_2_node3 = new ListNode(4);
        ListNode* c1_2_node2 = new ListNode(3);
        c1_2_node2->next = c1_2_node3;
        ListNode* c1_2_node1 = new ListNode(1);
        c1_2_node1->next = c1_2_node2;

        ListNode* res1 = sol->mergeTwoLists(c1_1_node1, c1_2_node1);
        print_res(res1);

        // case2
        ListNode* c2_1_node1 = NULL;
        ListNode* c2_2_node1 = NULL;
        ListNode* res2 = sol->mergeTwoLists(c2_1_node1, c2_2_node1);
        print_res(res2);

        // case3
        ListNode* c3_1_node1 = NULL;
        ListNode* c3_2_node1 = new ListNode(0);
        ListNode* res3 = sol->mergeTwoLists(c3_1_node1, c3_2_node1);
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


