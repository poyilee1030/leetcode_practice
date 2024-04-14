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
        while (n > 0) {
            fast = fast->next;
            n -= 1;
        }

        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return dummy->next;
	}

	void do_test(_0019_remove_nth_node_from_end_of_list *sol) {
        vector<int> nums;
        ListNode* head;
        ListNode* ret;

        nums = { 1, 2, 3, 4, 5 };
        head = create_ListNodes_from_vector(nums);
        ret = sol->removeNthFromEnd(head, 2);
        print_ListNode(ret);
        // Output: [ 1, 2, 3, 5 ]

        nums = { 1 };
        head = create_ListNodes_from_vector(nums);
        ret = sol->removeNthFromEnd(head, 1);
        print_ListNode(ret);
        // Output: [ ]

        nums = { 1, 2 };
        head = create_ListNodes_from_vector(nums);
        ret = sol->removeNthFromEnd(head, 1);
        print_ListNode(ret);
        // Output: [ 1 ]
	}
};
