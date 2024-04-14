#pragma once

#include <iostream>
#include "define.h"

using namespace std;


class _0025_reverse_nodes_in_k_group
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> heads;
        ListNode* p = head;

        int flag = 1;
        while (p) {
            heads.push_back(p);

            for (int i = 0; i < k - 1; i++) {
                if (p->next)
                    p = p->next;
                else
                    flag = 0;
            }

            ListNode* nxt = p->next;
            p->next = NULL;
            p = nxt;
        }

        for (int i = 0; i < heads.size(); i++) {
            if (flag != 0 || i != heads.size() - 1)
                heads[i] = reverseLinkedList(heads[i]);
        }

        for (int i = 0; i < heads.size() - 1; i++) {
            ListNode* h = heads[i];
            while (h->next)
                h = h->next;
            h->next = heads[i + 1];
        }

        return heads[0];
    }

    ListNode* reverseLinkedList(ListNode* h) {
        ListNode* last = NULL;
        ListNode* cur = h;
        ListNode* nxt;
        while (cur) {
            nxt = cur->next;
            cur->next = last;
            last = cur;
            cur = nxt;
        }
        return last;
    }

	void do_test(_0025_reverse_nodes_in_k_group* sol) {
        vector<int> nums;
        ListNode* head;
        ListNode* ret;
        
        nums = { 1, 2, 3, 4, 5 };
        head = create_ListNodes_from_vector(nums);
        ret = sol->reverseKGroup(head, 2);
        print_ListNode(ret);
        // Output: [ 2, 1, 4, 3, 5 ]

        head = create_ListNodes_from_vector(nums);
        ret = sol->reverseKGroup(head, 3);
        print_ListNode(ret);
        // Output: [ 3, 2, 1, 4, 5 ]
	}
};