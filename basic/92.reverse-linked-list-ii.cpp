/*
 * @lc app=leetcode.cn id=92 lang=cpp
 * @lcpr version=30113
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = &dummy;
        // 找left的pre为p
        for (int i = 1; i < left; ++i) {
            p = p->next;
        }
        ListNode* cur = p->next;
        ListNode* pre = nullptr;
        for (int i = left; i <= right; i++) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        p->next->next = cur;
        p->next = pre;
        return dummy.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n1\n
// @lcpr case=end

 */

