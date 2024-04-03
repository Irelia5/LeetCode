/*
 * @lc app=leetcode.cn id=309 lang=cpp
 * @lcpr version=30121
 *
 * [309] 买卖股票的最佳时机含冷冻期
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
    int maxProfit1(vector<int>& prices) {
        int n = prices.size();
        function<int(int, int)> dfs = [&] (int day, int hold) {
            if (day <= -1) {
                return hold ? INT_MIN : 0;
            }
            return hold ?
                    max(dfs(day - 1, 1), dfs(day - 2, 0) - prices[day]) :
                    max(dfs(day - 1, 0), dfs(day - 1, 1) + prices[day]);
        };
        return dfs(n - 1, 0);
    }

    int maxProfit2(vector<int>& prices) {
        int n = prices.size();
        int cache[n][2];
        memset(cache, -1, sizeof cache);
        function<int(int, int)> dfs = [&] (int day, int hold) {
            if (day <= -1) {
                return hold ? INT_MIN : 0;
            }
            auto& res = cache[day][hold];
            if (res != -1) return res;
            return res = hold ?
                    max(dfs(day - 1, 1), dfs(day - 2, 0) - prices[day]) :
                    max(dfs(day - 1, 0), dfs(day - 1, 1) + prices[day]);
        };
        return dfs(n - 1, 0);
    }

    int maxProfit3(vector<int>& prices) {
        int n = prices.size();
        int f[n + 2][2];
        memset(f, 0, sizeof f);
        f[0][1] = INT_MIN;
        f[1][1] = INT_MIN;
        for (int i = 0; i < n; ++i) {
            f[i + 2][0] = max(f[i + 1][0], f[i + 1][1] + prices[i]);
            f[i + 2][1] = max(f[i + 1][1], f[i][0] - prices[i]);
        }
        return f[n + 1][0];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int f0 = 0, pre0 = 0, f1 = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int new_f0 = max(f0, f1 + prices[i]);
            f1 = max(f1, pre0 - prices[i]);
            pre0 = f0;
            f0 = new_f0;
        }
        return f0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

