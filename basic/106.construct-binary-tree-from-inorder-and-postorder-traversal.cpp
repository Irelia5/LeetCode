/*
 * @lc app=leetcode.cn id=106 lang=cpp
 * @lcpr version=30202
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        function<TreeNode*(int, int, int, int)> build = [&] (int l1, int r1, int l2, int r2) -> TreeNode* {
            if (l1 > r1) return nullptr;
            TreeNode* node = new TreeNode(postorder[r2]);
            int x = 0;
            while (inorder[x + l1] != postorder[r2]) ++x;
            node->left = build(l1, l1 + x - 1, l2, l2 + x - 1);
            node->right = build(l1 + x + 1, r1, l2 + x, r2 - 1);
            return node;
        };
        int m = inorder.size();
        int n = postorder.size();
        return build(0, m - 1, 0, n - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

