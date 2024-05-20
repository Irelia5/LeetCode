/*
 * @lc app=leetcode.cn id=129 lang=cpp
 * @lcpr version=30202
 *
 * [129] 求根节点到叶节点数字之和
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
    int sumNumbers(TreeNode* root) {
        // 叶子
        // 非叶子
        sumNumbers(root, 0);
        return _ans;
    }

    void sumNumbers(TreeNode* root, int t) {
        if (!root->left && !root->right) {
            _ans += t * 10 + root->val;
        }
        if (root->left) sumNumbers(root->left, t * 10 + root->val);
        if (root->right) sumNumbers(root->right, t * 10 + root->val);
    }
    int _ans = 0;
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,9,0,5,1]\n
// @lcpr case=end

 */

