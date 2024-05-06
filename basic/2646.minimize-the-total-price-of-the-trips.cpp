/*
 * @lc app=leetcode.cn id=2646 lang=cpp
 * @lcpr version=30122
 *
 * [2646] 最小化旅行的价格总和
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
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        // 1 计算每个节点的经过次数
        // 2 打家劫舍

        // 建树
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            int x = e[0];
            int y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        // 计算节点经过次数
        vector<int> cnt(n, 0);
        for (const auto& trip : trips) {
            if (trip.empty()) continue;
            int start = trip[0];
            int end = trip[1];
            function<bool(int, int)> dfs = [&] (int x, int fa) -> bool {
                if (x == end) {
                    ++cnt[x];
                    return true;
                }
                for (const auto y : g[x]) {
                    if (y != fa && dfs(y, x)) {
                        ++cnt[x];
                        return true;
                    }
                }
                return false;
            };
            dfs(start, -1);
        }

        // 打家劫舍(选或不选)
        function<pair<int, int>(int, int)> dfs = [&] (int x, int fa) -> pair<int, int> {
            int non_discount = cnt[x] * price[x];
            int discount = non_discount / 2;
            for (auto y : g[x]) {
                if (y != fa) {
                    auto [non_dis, dis] = dfs(y, x);
                    discount += non_dis;
                    non_discount += min(non_dis, dis);
                }
            }
            return {non_discount, discount};
        };
        auto [non_dis, dis] = dfs(0, -1);
        return min(non_dis, dis);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[[0,1],[1,2],[1,3]]\n[2,2,10,6]\n[[0,3],[2,1],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[0,1]]\n[2,2]\n[[0,0]]\n
// @lcpr case=end

 */

