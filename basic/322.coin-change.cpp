/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=30119
 *
 * [322] 零钱兑换
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
    int coinChange1(vector<int>& coins, int amount) {
        int n = coins.size();
        function<int(int, int)> dfs = [&] (int i, int c) -> int {
            if (i < 0) return c == 0 ? 0 : INT_MAX / 2;
            if (c < coins[i]) return dfs(i - 1, c);
            return min(dfs(i - 1, c), dfs(i, c - coins[i]) + 1);
        };
        int res = dfs(n - 1, amount);
        return  res == INT_MAX / 2 ? -1 : res;
    }

    int coinChange2(vector<int>& coins, int amount) {
        int n = coins.size();
        int cache[n][amount + 1];
        memset(cache, -1 ,sizeof(cache));
        function<int(int, int)> dfs = [&] (int i, int c) -> int {
            if (i < 0) return c == 0 ? 0 : INT_MAX / 2;
            int& res = cache[i][c];
            if (-1 != res) return res;
            if (c < coins[i]) return res = dfs(i - 1, c);
            return res = min(dfs(i - 1, c), dfs(i, c - coins[i]) + 1);
        };
        int ans = dfs(n - 1, amount);
        return  ans == INT_MAX / 2 ? -1 : ans;
    }

    // 递推
    int coinChange3(vector<int>& coins, int amount) {
        int n = coins.size();
        int f[n + 1][amount + 1];
        memset(f, 0x3f, sizeof(f));

        f[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int c = 0; c <= amount; ++c) {
                if (c < coins[i]) f[i + 1][c] = f[i][c];
                else f[i + 1][c] = min(f[i][c], f[i + 1][c - coins[i]] + 1);
            }
        }
        
        int ans = f[n][amount];
        return  ans < 0x3f3f3f3f ? ans : -1;
    }

    // 两个数组
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int f[amount + 1];
        memset(f, 0x3f, sizeof(f));

        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int c = 0; c <= amount; ++c) {
                if (c >= coins[i]) f[c] = min(f[c], f[c - coins[i]] + 1);
            }
        }
        
        int ans = f[amount];
        return  ans < 0x3f3f3f3f ? ans : -1;
    }

};
// @lc code=end



/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

