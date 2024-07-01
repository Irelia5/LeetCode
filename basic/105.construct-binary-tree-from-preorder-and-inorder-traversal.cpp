/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=30202
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        function<TreeNode*(int, int, int, int)> build = [&] (int l1, int r1, int l2, int r2) ->TreeNode* {
            if (l1 > r1) return nullptr;
            TreeNode* node = new TreeNode(preorder[l1]);
            int x = 0;
            while (inorder[l2 + x] != preorder[l1]) ++x;

            node->left = build(l1 + 1, l1 + x, l2, l2 + x - 1);
            // std::cout << "success" << " ";
            node->right = build(l1 + x + 1, r1, l2 + x + 1, r2);
            return node;
        };
        int m = preorder.size();
        int n = inorder.size();
        return build(0, m - 1, 0, n - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

