/*
 * @lc app=leetcode.cn id=2816 lang=cpp
 * @lcpr version=30114
 *
 * [2816] 翻倍以链表形式表示的数字
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
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        head = doubleItImp(head, 0);
        return reverseList(head);
    }

    ListNode* doubleItImp(ListNode* head, int carry) {
        if (!head && !carry) return nullptr;
        if (head) {
            carry += head->val * 2;
            head = head->next;
        }
        ListNode* node = new ListNode(carry % 10);
        node->next = doubleItImp(head, carry / 10);
        return node;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,8,9]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9]\n
// @lcpr case=end

 */

