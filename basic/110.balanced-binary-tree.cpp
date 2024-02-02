/*
 * @lc app=leetcode.cn id=110 lang=cpp
 * @lcpr version=30114
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return isBalancedTree(root) != -1;
    }
    int isBalancedTree(TreeNode* root) {
        if (!root) return 0;
        int left_height = isBalancedTree(root->left);
        if (-1 == left_height) return -1;
        int right_height = isBalancedTree(root->right);
        if (-1 == right_height) return - 1;

        int height = abs(left_height - right_height);
        if (height > 1) return -1;
        return max(left_height, right_height) + 1;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,3,3,null,null,4,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

