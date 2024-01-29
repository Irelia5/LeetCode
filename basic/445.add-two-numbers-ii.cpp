/*
 * @lc app=leetcode.cn id=445 lang=cpp
 * @lcpr version=30114
 *
 * [445] 两数相加 II
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // 递归
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* node = addTwoNum(l1, l2, 0);
        return reverseList(node);
    }

    ListNode* addTwoNum(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2 && !carry) return nullptr;
        if (l1) {
            carry += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            carry += l2->val;
            l2 = l2->next;
        }
        ListNode* cur = new ListNode(carry % 10);
        cur->next = addTwoNum(l1, l2, carry / 10);
        return cur;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }

    // 迭代
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        ListNode* l1_re = reverseList2(l1);
        ListNode* l2_re = reverseList2(l2);
        int carry = 0; // 进位
        ListNode dummy(0);
        ListNode *pre = &dummy;
        while (l1_re || l2_re || carry) {
            if (l1_re) carry += l1_re->val;
            if (l2_re) carry += l2_re->val;
            ListNode *cur = new ListNode(carry % 10);
            pre->next = cur;
            pre = cur;
            carry /= 10;
            if (l1_re) l1_re = l1_re->next;
            if (l2_re) l2_re = l2_re->next;
        }
        return reverseList2(dummy.next);
    }

    ListNode* reverseList2(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

 */

