/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=30114
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        ListNode* pre = &dummy;
        pre->next = head;

        ListNode* cur = pre->next;
        while (cur && cur->next) {
            ListNode* nxt = cur->next->next;
            pre->next = cur->next;
            cur->next->next = cur;
            cur->next = nxt;
            pre = cur;
            cur = nxt;
        }
        return dummy.next;
    }
    // 递归
    ListNode* swapPairs2(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* nxt = swapPairs(head->next->next);
        ListNode* node = head->next;
        node->next = head;
        head->next = nxt;
        return node;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

