/*
 * @Date: 2021-01-23 21:43:47
 * @LastEditTime: 2021-01-24 14:21:05
 * @LinkPath: https://leetcode-cn.com/problems/merge-two-sorted-lists/
 */

#include<iostream>
using namespace std;

//
// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
// 输入：l1 = [1,2,4], l2 = [1,3,4]
// 输出：[1,1,2,3,4,4]

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        ListNode* prev = nullptr;
        ListNode* cur = nullptr;
        ListNode* head = nullptr;

        while (l1 != nullptr && l2 != nullptr) {
            cur = (l1->val < l2->val) ? l1 : l2;
            if (head == nullptr) {
                head = cur;
            } else {
                prev->next = cur;
            }
            prev = cur;

            if (cur == l1) {
                l1 = l1->next;
            } else {
                l2 = l2->next;
            }
        }
        prev->next = l1 == nullptr ? l2 : l1;
        return head;

    }


/* vim: set ts=4 sw=4 sts=4 tw=100 */
