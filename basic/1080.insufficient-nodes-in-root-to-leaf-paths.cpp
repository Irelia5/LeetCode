/*
 * @lc app=leetcode.cn id=1080 lang=cpp
 * @lcpr version=30114
 *
 * [1080] 根到叶路径上的不足节点
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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        // 叶子
        limit -= root->val;
        if (!root->left && !root->right) return limit <= 0 ? root : nullptr;
        // 非叶子节点
        if (root->left) root->left = sufficientSubset(root->left, limit);
        if (root->right) root->right = sufficientSubset(root->right, limit);
        return root->left || root->right ? root : nullptr;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14]\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,11,null,17,4,7,1,null,null,5,3]\n22\n
// @lcpr case=end

// @lcpr case=start
// [1,2,-3,-5,null,4,null]\n-1\n
// @lcpr case=end

 */

