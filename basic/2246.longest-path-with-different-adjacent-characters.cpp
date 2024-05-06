/*
 * @lc app=leetcode.cn id=2246 lang=cpp
 * @lcpr version=30121
 *
 * [2246] 相邻字符不同的最长路径
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
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> g(n);
        for (int i = 1; i < n; ++i) {
            g[parent[i]].push_back(i);
        }
        int ans = 0;
        function<int(int)> dfs = [&](int x) {
            int x_len = 0;
            for (auto y : g[x]) {
                int y_len = dfs(y) + 1;
                if (s[x] == s[y]) continue; // 这行的位置很重要
                ans = max(ans, x_len + y_len);
                x_len = max(x_len, y_len);
            }
            return x_len;
        };
        dfs(0);
        return ans + 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,0,0,1,1,2]\n"abacbe"\n
// @lcpr case=end

// @lcpr case=start
// [-1,0,0,0]\n"aabc"\n
// @lcpr case=end

 */

