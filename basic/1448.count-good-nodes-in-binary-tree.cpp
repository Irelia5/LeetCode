/*
 * @lc app=leetcode.cn id=1448 lang=cpp
 * @lcpr version=30202
 *
 * [1448] 统计二叉树中好节点的数目
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
    int goodNodes(TreeNode* root) {
        goodNodes(root, root->val);
        return _ans;
    }
    void goodNodes(TreeNode* root, int max_val) {
        if (!root) return;
        if (root->val >= max_val) {
            max_val = root->val;
            ++_ans;
        }
        goodNodes(root->left, max_val);
        goodNodes(root->right, max_val);
    }

    int _ans = 0;
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,4,3,null,1,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,null,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

