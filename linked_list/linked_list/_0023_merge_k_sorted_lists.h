#pragma once

#include <iostream>
#include <vector>
#include "define.h"

using namespace std;


class _0023_merge_k_sorted_lists
{
public:
    // �� min_idx, min_val ���N�W�@���� next_node, leetcode 214ms
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

    /* �ۤv�Q��, leetcode 489ms
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
