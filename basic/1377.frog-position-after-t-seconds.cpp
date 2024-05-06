/*
 * @lc app=leetcode.cn id=1377 lang=cpp
 * @lcpr version=30122
 *
 * [1377] T 秒后青蛙的位置
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
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        // 建树
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int x = e[0] - 1;
            int y = e[1] - 1;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        --target;

        double ans;
        function<void(int, int, int, double)> dfs = [&] (int x, int fa, int count, double p) {
            if (count == t) {
                if (x == target) ans = p;
                return;
            }
            
            int c = fa == -1 ? g[x].size() : g[x].size() - 1;
            if (c == 0) {
                if (x == target) ans = p;
                return;
            }
            for (auto y : g[x]) {
                if (y == fa) continue;
                dfs(y, x, count + 1, p / c);
            }

        };
        dfs(0, -1, 0, 1);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// 7\n[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]\n1\n7\n
// @lcpr case=end

 */

