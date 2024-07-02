/*
 * @lc app=leetcode.cn id=23 lang=cpp
 * @lcpr version=30204
 *
 * [23] 合并 K 个升序链表
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
    
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        auto my_compare = [](const ListNode* l1, const ListNode* l2) {
            return l1->val > l2->val;
        };
        // 小根堆
        priority_queue<ListNode*, vector<ListNode*>, decltype(my_compare)> pq;
        for (auto list : lists) {
            if (list) pq.push(list);
        }
        ListNode dummy;
        ListNode* cur = &dummy;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            if (node->next) pq.push(node->next);
            cur->next = node;
            cur = node;
        }
        return dummy.next;
    }

    // 归并
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* cur = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return dummy.next;
    }

    // 合并 [start, end] list
    ListNode* mergeListK(vector<ListNode*>& lists, int start, int end) {
        if (start > end) return nullptr;
        if (start == end) return lists[start];
        auto left = mergeListK(lists, start, (start + end) / 2);
        auto right = mergeListK(lists, (start + end) / 2 + 1, end);
        return mergeTwoLists(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeListK(lists, 0, lists.size() - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */

