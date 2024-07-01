/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 * @lcpr version=30202
 *
 * [1373] 二叉搜索子树的最大键值和
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
    // 题目的意思是找出二叉树中的二叉搜索子树
    // 并计算二叉搜索子树的最大值和
    // 思路:后续遍历验证二叉搜索树, 并更新最大值
    int maxSumBST(TreeNode* root) {
        BST(root);
        return _ans;
    }

    tuple<int, int, int> BST(TreeNode* root) {
        if (!root) return {INT_MAX, INT_MIN, 0};
        auto [left_min, left_max, left_sum] = BST(root->left);
        auto [right_min, right_max, right_sum] = BST(root->right);
        if (left_min == INT_MIN) return {INT_MIN, INT_MAX, 0};
        if (right_min == INT_MIN) return {INT_MIN, INT_MAX, 0};
        if (left_max < root->val && root->val < right_min) {
            // 满足二叉搜索树
            int sum = left_sum + right_sum + root->val;
            _ans = max(_ans, sum);
            return {min(left_min, root->val), max(right_max, root->val), sum};
        }
        return {INT_MIN, INT_MAX, 0};
        
    }
    int _ans = 0;
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]\n
// @lcpr case=end

// @lcpr case=start
// [4,3,null,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [-4,-2,-5]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,3,null,6,3]\n
// @lcpr case=end

 */

