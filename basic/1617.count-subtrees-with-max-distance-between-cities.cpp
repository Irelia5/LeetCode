/*
 * @lc app=leetcode.cn id=1617 lang=cpp
 * @lcpr version=30122
 *
 * [1617] 统计子树中城市之间最大距离
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
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        // 构建树
        // g[i] 表示以i为父节点的节点集合
        for (auto& edge : edges) {
            int x = edge[0] - 1, y = edge[1] - 1;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        // 遍历子集
        // dfs(i) 表示 由 i -> n -1数组的所有子集 的最大树直径
        vector<int> in_sets(n, false);
        vector<int> vis(n, false);
        vector<int> ans(n - 1);
        int diameter = 0;

        function<int(int)> f = [&] (int x) -> int {
            vis[x] = true;
            int x_len = 0;
            for (auto y : g[x]) {
                if (!vis[y] && in_sets[y]) {
                    int y_len = f(y) + 1;
                    diameter = max(diameter, x_len + y_len);
                    x_len = max(x_len, y_len);
                }
            }
            return x_len;
        };

        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                // 计算树最大直径

                for (int v = 0; v < n; ++v) {
                    if (in_sets[v]) {
                        fill(vis.begin(), vis.end(), false);
                        diameter = 0;
                        f(v);
                        break;
                    }
                    
                }
                if (diameter && vis == in_sets) {
                    ++ans[diameter - 1];
                }
                return;
            }
            // 不选
            dfs(i + 1);
            // 选
            in_sets[i] = true;
            dfs(i + 1);
            in_sets[i] = false;
            return;
        };

        dfs(0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[[1,2],[2,3],[2,4]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,2],[2,3]]\n
// @lcpr case=end

 */

