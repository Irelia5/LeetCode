/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 * @lcpr version=30114
 *
 * [1026] 节点与其祖先之间的最大差值
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
    int maxAncestorDiff(TreeNode* root) {
        return maxAncestorDiff(root, root->val, root->val);
    }

    int maxAncestorDiff(TreeNode* root, int mx, int mn) {
        if (root == nullptr) return 0;
        mx = max(mx, root->val);
        mn = min(mn, root->val);
        int left_max = maxAncestorDiff(root->left, mx, mn);
        int right_max = maxAncestorDiff(root->right, mx, mn);
        int val = max(mx - root->val, root->val - mn);
        return left_max > right_max
                  ? (left_max > val ? left_max : val) 
                  : (right_max > val ? right_max : val);

    }
};
// @lc code=end



/*
// @lcpr case=start
// [8,3,10,1,6,null,14,null,null,4,7,13]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2,null,0,3]\n
// @lcpr case=end

 */

