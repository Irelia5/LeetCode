/*
 * @lc app=leetcode.cn id=714 lang=cpp
 * @lcpr version=30203
 *
 * [714] 买卖股票的最佳时机含手续费
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
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int f[n + 1][2];
        memset(f, 0, sizeof f);
        f[0][1] = INT_MIN / 2;
        f[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            f[i+1][0] = max(f[i][1] + prices[i], f[i][0]);
            f[i+1][1] = max(f[i][0] - prices[i] - fee, f[i][1]);
        }
        return f[n][0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 3, 2, 8, 4, 9]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,7,5,10,3]\n3\n
// @lcpr case=end

 */

