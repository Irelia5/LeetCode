/*
 * @lc app=leetcode.cn id=98 lang=cpp
 * @lcpr version=30116
 *
 * [98] 验证二叉搜索树
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
class Solution1 {
public:
    // pre-order-traversal
    bool isValidBST(TreeNode* root) {
        return isValidBSTPre(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBSTPre(TreeNode* root, long left, long right) {
        if (!root) return true;
        long x = root->val;
        return x < right
               && x > left
               && isValidBSTPre(root->left, left, x)
               && isValidBSTPre(root->right, x, right);
    }
};

class Solution {
public:
    // pre-order-traversal
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (!isValidBST(root->left) || root->val <= _pre_val) return false;
        _pre_val = root->val;
        return isValidBST(root->right);
    }
private:
    long _pre_val = LONG_MIN;
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */

