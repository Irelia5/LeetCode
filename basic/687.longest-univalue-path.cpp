/*
 * @lc app=leetcode.cn id=687 lang=cpp
 * @lcpr version=30122
 *
 * [687] 最长同值路径
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
    // 思路：枚举拐弯处节点, 计算最大值
    // 当前拐弯处直径: left_len + right_len
    // left_len = left_val == cur_val ? left_len + 1 : 0
    // right_len = right_val == cur_val ? right_len + 1 : 0
    // 返回给父节点: max(left_len, right_len)
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> dfs = [&] (TreeNode* node) -> int {
            if (!node) return 0;
            int left_len = dfs(node->left);
            int right_len = dfs(node->right);
            left_len = (node->left && node->left->val == node->val) ? left_len + 1 : 0;
            right_len = (node->right && node->right->val == node->val) ? right_len + 1 : 0;
            ans = max(ans, left_len + right_len);
            return max(left_len, right_len);
        };
        dfs(root);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,5,1,1,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,4,5,4,4,5]\n
// @lcpr case=end

 */

