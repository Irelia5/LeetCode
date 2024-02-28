/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 * @lcpr version=30117
 *
 * [1123] 最深叶节点的最近公共祖先
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto [res, depth] = dfs(root);
        return res;
    }
private:
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (!root) return {nullptr, 0};
        auto [left_node, left_depth] = dfs(root->left);
        auto [right_node, right_depth] = dfs(root->right);
        if (left_depth == right_depth) return {root, left_depth + 1};
        else if (left_depth < right_depth) return {right_node, right_depth + 1};
        else return {left_node, left_depth + 1};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,3,null,2]\n
// @lcpr case=end

 */

