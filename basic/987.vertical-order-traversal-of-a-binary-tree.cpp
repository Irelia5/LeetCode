/*
 * @lc app=leetcode.cn id=987 lang=cpp
 * @lcpr version=30202
 *
 * [987] 二叉树的垂序遍历
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

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        for (auto & [_, g] : groups) {
            ranges::sort(g);
            vector<int> vals;
            for (auto & [_, val] : g) {
                vals.push_back(val);
            }
            ans.push_back(vals);
        }
        return ans;
    }

    void dfs(TreeNode* root, int row, int col) {
        if (!root) return;
        groups[col].emplace_back(row, root->val);
        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }
private:
    map<int, vector<pair<int, int>>> groups;
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,6,5,7]\n
// @lcpr case=end

 */

