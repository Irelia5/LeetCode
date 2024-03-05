/*
 * @lc app=leetcode.cn id=51 lang=cpp
 * @lcpr version=30117
 *
 * [51] N 皇后
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
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> col(n); // 每行的皇后位置
        vector<int> diag1 (2 * n - 1); // 斜率 - 1 截距是否存在
        vector<int> diag2(2 * n - 1); // 斜率 1 截距是否存在
        vector<int> on_path(n); //某一列是否放了皇后 

        function<void(int)> dfs = [&] (int r) {
            if (r == n) {
                // 构造结构
                vector<string> path;
                for (int i = 0; i < n; ++i) {
                    string s (n, '.');
                    s[col[i]] = 'Q';
                    path.emplace_back(s);
                }
                ans.emplace_back(path);
                return;
            }
            // 构造本行可放的位置 及 准备下一行可放的位置
            for (int c = 0; c < n; ++c) {
                int rc = r - c + n - 1;
                if (!on_path[c] && !diag1[r+c] && !diag2[rc]) {
                    col[r] = c;
                    on_path[c] = true;
                    diag1[r+c] = true;
                    diag2[rc] = true;
                    dfs(r + 1);
                    on_path[c] = false;
                    diag1[r+c] = false;
                    diag2[rc] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

