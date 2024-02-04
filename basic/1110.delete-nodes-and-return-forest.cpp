/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 * @lcpr version=30114
 *
 * [1110] 删点成林
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (auto n : to_delete) _to_delete.insert(n);
        if (delNodes(root)) _ans.push_back(root);
        return _ans;
    }
private:
    TreeNode* delNodes(TreeNode* root) {
        if (!root) return nullptr;
        root->left = delNodes(root->left);
        root->right = delNodes(root->right);
        if (!_to_delete.count(root->val)) return root;
        if (root->left) _ans.push_back(root->left);
        if (root->right) _ans.push_back(root->right);
        return nullptr;
    }
private:
    unordered_set<int> _to_delete;
    vector<TreeNode*> _ans;
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,7]\n[3,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,4,null,3]\n[3]\n
// @lcpr case=end

 */

