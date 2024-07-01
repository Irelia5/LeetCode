/*
 * @lc app=leetcode.cn id=2476 lang=cpp
 * @lcpr version=30202
 *
 * [2476] 二叉搜索树最近节点查询
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> in_order;
        function<void(TreeNode*)> dfs = [&] (TreeNode* node) -> void {
            if (!node) return;
            dfs(node->left);
            in_order.push_back(node->val);
            dfs(node->right);
        };
        dfs(root);
        vector<vector<int>> ans;
        for (auto query : queries) {
            auto low = lower_bound(in_order.begin(), in_order.end(), query);
            int mx = low == in_order.end() ? -1 : *low;
            auto up = upper_bound(in_order.begin(), in_order.end(), query);
            int mn = -1;
            if (up != in_order.begin()) {
                advance(up, -1);
                mn = *up;
            }
            ans.push_back({mn, mx});
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [6,2,13,1,4,9,15,null,null,null,null,null,null,14]\n[2,5,16]\n
// @lcpr case=end

// @lcpr case=start
// [4,null,9]\n[3]\n
// @lcpr case=end

 */

