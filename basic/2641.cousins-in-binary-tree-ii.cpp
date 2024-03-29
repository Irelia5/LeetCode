/*
 * @lc app=leetcode.cn id=2641 lang=cpp
 * @lcpr version=30117
 *
 * [2641] 二叉树的堂兄弟节点 II
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        root->val = 0;
        while (!q.empty()) {
            vector<TreeNode*> nodes;
            int sum = 0;
            for (int i = q.size(); i > 0; --i) {
                auto node = q.front();
                q.pop();
                nodes.push_back(node);
                if (node->left) {
                    q.push(node->left);
                    sum += node->left->val;
                }
                if (node->right) {
                    q.push(node->right);
                    sum += node->right->val;
                }
            }
            for (auto node : nodes) {
                int val = 0;
                if (node->left) val += node->left->val;
                if (node->right) val += node->right->val;
                if (node->left) node->left->val = sum - val;
                if (node->right) node->right->val = sum - val;
            }
        }
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,9,1,10,null,7]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,2]\n
// @lcpr case=end

 */

