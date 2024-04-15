#pragma once

#include <iostream>
#include <vector>
#include "define.h"

using namespace std;


class _0023_merge_k_sorted_lists
{
public:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* merged = new ListNode(-1);
        ListNode* mptr = merged;
        ListNode* left = list1;
        ListNode* right = list2;

        while (left != NULL && right != NULL) {
            if (left->val <= right->val) {
                mptr->next = left;
                mptr = mptr->next;
                left = left->next;
            }
            else {
                mptr->next = right;
                mptr = mptr->next;
                right = right->next;
            }
        }
        if (left != NULL) {
            mptr->next = left;
        }
        if (right != NULL) {
            mptr->next = right;
        }

        return merged->next;
    }

    // leetcode 122ms
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }

        if (lists.size() == 1) {
            return lists[0];
        }

        ListNode* head = lists[0];
        for (int i = 1; i < lists.size(); ++i) {
            head = merge(head, lists[i]);
        }

        return head;
    }

    /* 用 min_idx, min_val 取代上一版的 next_node, leetcode 214ms
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        bool valid = true;
        while (valid) {
            valid = false;
            int min_val = INT_MAX;
            int min_idx = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == NULL)
                    continue;

                valid = true;
                if (lists[i]->val <= min_val) {
                    min_val = lists[i]->val;
                    min_idx = i;
                }
            }
            if (min_idx == -1)
                break;
            else {
                curr->next = lists[min_idx];
                curr = curr->next;
                lists[min_idx] = lists[min_idx]->next;
            }
        }
        return dummy->next;
    }
    */

    /* 自己想的, leetcode 489ms
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        ListNode* next_node = NULL;

        bool valid = true;
        while (valid) {
            valid = false;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == NULL)
                    continue;

                valid = true;
                if (next_node == NULL)
                    next_node = lists[i];
                else {
                    if (lists[i]->val <= next_node->val)
                        next_node = lists[i];
                }
            }
            if (next_node == NULL)
                break;
            else {
                for (int i = 0; i < lists.size(); i++) {
                    if (lists[i] == next_node)
                        lists[i] = lists[i]->next;
                }
                curr->next = next_node;
                curr = curr->next;
                next_node = NULL;
            }
        }
        return dummy->next;
	}
    */
	

	void do_test(_0023_merge_k_sorted_lists *sol) {
        vector<ListNode*> lists;
        ListNode* ret;

        vector<int> nums1 = { 1, 4, 5 };
        vector<int> nums2 = { 1, 3, 4 };
        vector<int> nums3 = { 2, 6 };
        ListNode* head1 = create_ListNodes_from_vector(nums1);
        ListNode* head2 = create_ListNodes_from_vector(nums2);
        ListNode* head3 = create_ListNodes_from_vector(nums3);
        lists = { head1, head2, head3 };
        ret = sol->mergeKLists(lists);
        print_ListNode(ret);

        lists = { };
        ret = sol->mergeKLists(lists);
        print_ListNode(ret);

        lists = { NULL };
        ret = sol->mergeKLists(lists);
        print_ListNode(ret);
	}
};
