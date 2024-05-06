/*
 * @lc app=leetcode.cn id=188 lang=cpp
 * @lcpr version=30121
 *
 * [188] 买卖股票的最佳时机 IV
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
    int maxProfit1(int k, vector<int>& prices) {
        int n = prices.size();
        function<int(int, int, int)> dfs = [&] (int i, int j, int hold) {
            if (j < 0) return INT_MIN;
            if (i < 0) return hold == 0 ?
                                0 : INT_MIN;
            return hold ?
                    max(dfs(i - 1, j, 1), dfs(i - 1, j - 1, 0) - prices[i]) :
                    max(dfs(i - 1, j, 0), dfs(i - 1, j - 1, 1) + prices[i]);
        };
        return dfs(n - 1, k, 0);
    }

    int maxProfit2(int k, vector<int>& prices) {
        int n = prices.size();
        int cache [n][k + 1][2];
        memset(cache, -1, sizeof cache);
        function<int(int, int, int)> dfs = [&] (int i, int j, int hold) {
            if (j < 0) return INT_MIN;
            if (i < 0) return hold == 0 ?
                                0 : INT_MIN;
            auto& res = cache[i][j][hold];
            if (-1 != res) return res;
            return res = hold ?
                    max(dfs(i - 1, j, 1), dfs(i - 1, j, 0) - prices[i]) :
                    max(dfs(i - 1, j, 0), dfs(i - 1, j - 1, 1) + prices[i]);
        };
        return dfs(n - 1, k, 0);
    }

    int maxProfit3(int k, vector<int>& prices) {
        int n = prices.size();
        int f [n + 1][k + 2][2];
        memset(f, - 0x3f, sizeof f);
        for (int j = 1; j <= k + 1; ++j) f[0][j][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                f[i + 1][j + 1][0] = max(f[i][j + 1][0], f[i][j + 1][1] + prices[i]);
                f[i + 1][j + 1][1] = max(f[i][j + 1][1], f[i][j][0] - prices[i]);
            }
        }
        return f[n][k + 1][0];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int f [k + 2][2];
        memset(f, - 0x3f, sizeof f);
        for (int j = 1; j <= k + 1; ++j) f[j][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                f[j + 1][0] = max(f[j + 1][0], f[j + 1][1] + prices[i]);
                f[j + 1][1] = max(f[j + 1][1], f[j][0] - prices[i]);
            }
        }
        return f[k + 1][0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[2,4,1]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[3,2,6,5,0,3]\n
// @lcpr case=end

 */

