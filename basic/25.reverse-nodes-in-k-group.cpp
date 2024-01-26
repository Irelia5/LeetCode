/*
 * @lc app=leetcode.cn id=25 lang=cpp
 * @lcpr version=30113
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tra = head;
        int sum = 0;
        while (tra) {
            tra = tra->next;
            ++sum;
        }

        ListNode dummy(0);
        ListNode* p = &dummy;
        p->next = head;

        while (sum - k >= 0) {
            sum -= k;
            ListNode* cur = p->next;
            ListNode* pre = nullptr;

            for (int i = 0; i < k; ++i) {
                ListNode* nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            p->next->next = cur;
            ListNode* tmp = p->next;
            p->next = pre;
            p = tmp;
        }
        return dummy.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */

