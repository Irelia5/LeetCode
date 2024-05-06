/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 * @lcpr version=30122
 *
 * [1019] 链表中的下一个更大节点
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<pair<int, ListNode*>> st;
        for (int i = 0; head; i++, head = head->next) {
            ans.push_back(0);
            while (!st.empty() && st.top().second->val < head->val) {
                ans[st.top().first] = head->val;
                st.pop();
            }
            st.push(make_pair(i, head));
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,4,3,5]\n
// @lcpr case=end

 */

