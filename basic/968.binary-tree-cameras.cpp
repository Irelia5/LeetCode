/*
 * @lc app=leetcode.cn id=968 lang=cpp
 * @lcpr version=30122
 *
 * [968] 监控二叉树
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
    int minCameraCover(TreeNode* root) {
        function<tuple<int, int, int>(TreeNode*)> dfs = [&] (TreeNode* node) -> tuple<int, int, int> {
            if (!node) return {INT_MAX, 0, 0};
            auto [left_blue, left_yellow, left_red] = dfs(node->left);
            auto [right_blue, right_yellow, right_red] = dfs(node->right);
            int yellow = min(left_blue, left_red) + min(right_blue, right_red);
            int red = yellow + max(0, min(left_blue - left_red, right_blue - right_red));
            int blue = min(left_blue, left_yellow) + min(right_blue, right_yellow) + 1;
            return {blue, yellow, red};
        };
        auto [blue, yellow, red] = dfs(root);
        return min (blue, red);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,0,null,0,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,null,0,null,0,null,null,0]\n
// @lcpr case=end

 */

