/*
 * @lc app=leetcode.cn id=2415 lang=cpp
 * @lcpr version=30117
 *
 * [2415] 反转二叉树的奇数层
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        bool is_odd = false;
        for (; !q.empty(); is_odd = !is_odd) {
            vector<TreeNode*> trees;
            for (int i = q.size(); i > 0; --i) {
                auto node = q.front();
                q.pop();
                trees.push_back(node);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (is_odd) reverseTree(trees);
        }
        return root;
    }
    void reverseTree(std::vector<TreeNode*> vec) {
        int n = vec.size();
        for (int i = 0; i < n / 2; ++i) {
            swap(vec[i]->val, vec[n - i - 1]->val);
        }

    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,5,8,13,21,34]\n
// @lcpr case=end

// @lcpr case=start
// [7,13,11]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]\n
// @lcpr case=end

 */

