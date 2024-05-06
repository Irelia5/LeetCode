/*
 * @lc app=leetcode.cn id=2538 lang=cpp
 * @lcpr version=30122
 *
 * [2538] 最大价值和与最小价值和的差值
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
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        // 建树
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        long ans = 0;
        // 以下标为x的节点为根节点的消耗值
        // first 带叶节点的最大价值和
        // second 不带叶节点的最大价值和
        function<pair<long, long>(int, int)> dfs = [&] (int x, int fa) -> pair<long, long> {
            long s1_max = price[x];
            long s2_max = 0;
            for (auto y : g[x]) {
                if (y == fa) continue;
                auto [s1, s2] = dfs(y, x);
                ans = max(ans, max(s1 + s2_max, s1_max + s2));
                s1_max = max(s1_max, s1 + price[x]);
                s2_max = max(s2_max, s2 + price[x]);
            }
            return {s1_max, s2_max};
        };
        dfs(0, -1);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 6\n[[0,1],[1,2],[1,3],[3,4],[3,5]]\n[9,8,7,6,10,5]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1],[1,2]]\n[1,1,1]\n
// @lcpr case=end

 */

