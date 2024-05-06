/*
 * @lc app=leetcode.cn id=337 lang=cpp
 * @lcpr version=30121
 *
 * [337] 打家劫舍 III
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
    int rob(TreeNode* root) {
        function<pair<int, int>(TreeNode*)>dfs = [&] (TreeNode* node) -> pair<int, int> {
            if (!node) return {0, 0};
            auto [left_rob, left_no_rob] = dfs(node->left);
            auto [right_rob, right_no_rob] = dfs(node->right);

            int rob_it = left_no_rob + right_no_rob + node->val;
            int no_rob_it = max(left_rob, left_no_rob) + max(right_rob, right_no_rob);
            return {rob_it, no_rob_it};
        };
        auto [left_val, right_val] = dfs(root);
        return max(left_val, right_val);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,3,null,3,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,3,null,1]\n
// @lcpr case=end

 */

