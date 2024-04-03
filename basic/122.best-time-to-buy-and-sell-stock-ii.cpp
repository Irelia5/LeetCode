/*
 * @lc app=leetcode.cn id=122 lang=cpp
 * @lcpr version=30119
 *
 * [122] 买卖股票的最佳时机 II
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
            if (day == -1) {
                return hold ? INT_MIN : 0;
            }
            return hold ?
                       max(dfs(day - 1, 1), dfs(day - 1, 0) - prices[day]) :
                       max(dfs(day - 1, 0), dfs(day - 1, 1) + prices[day]);
        };
        return dfs(n - 1, 0);
    }

    // 记忆化搜索
    int maxProfit2(vector<int>& prices) {
        int n = prices.size();
        int cache[n][2];
        memset(cache, -1, sizeof cache);
        function<int(int, int)> dfs = [&] (int day, int hold) {
            if (day == -1) {
                return hold ? INT_MIN : 0;
            }
            int& res = cache[day][hold];
            if (-1 != res) return res;
            return res = hold ?
                       max(dfs(day - 1, 1), dfs(day - 1, 0) - prices[day]) :
                       max(dfs(day - 1, 0), dfs(day - 1, 1) + prices[day]);
        };
        return dfs(n - 1, 0);
    }

    // 递推
    int maxProfit3(vector<int>& prices) {
        int n = prices.size();
        int f[n + 1][2];
        memset(f, 0, sizeof f);
        f[0][0] = 0;
        f[0][1] = INT_MIN;
        for (int i = 0; i < n; i++) {
            f[i + 1][0] = max(f[i][0], f[i][1] + prices[i]);
            f[i + 1][1] = max(f[i][1], f[i][0] - prices[i]);
        }
        return f[n][0];
    }

    // 滚动数组
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int f0 = 0;
        int f1 = INT_MIN;
        for (int i = 0; i < n; i++) {
            int new_f0 = max(f0, f1 + prices[i]);
            f1 = max(f1, f0 - prices[i]);
            f0 = new_f0;
        }
        return f0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */

