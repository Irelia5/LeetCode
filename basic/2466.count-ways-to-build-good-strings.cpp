/*
 * @lc app=leetcode.cn id=2466 lang=cpp
 * @lcpr version=30119
 *
 * [2466] 统计构造好字符串的方案数
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
    // 回溯 超时
    int countGoodStrings1(int low, int high, int zero, int one) {
        int mod = 1000000007;
        function<int(int)> dfs = [&] (int i) {
            if (i > high) return 0;
            int cnt = i >= low;
            return (cnt + dfs(i + zero) + dfs(i + one)) % mod;
        };
        return dfs(0);
    }
    // 回溯 + 记忆化搜索  也超时了
    int countGoodStrings2(int low, int high, int zero, int one) {
        int mod = 1000000007;
        vector<int> cache(high, -1);
        function<int(int)> dfs = [&] (int i) {
            if (i > high) return 0;
            auto& res = cache[i];
            if (-1 != res) return res;
            int cnt = i >= low;
            return res = (cnt + dfs(i + zero) + dfs(i + one)) % mod;
        };
        return dfs(0);
    }
    // 用上面的回溯似乎很难转化为递推, 不如用爬楼梯的思路来考虑
    // 递推
    int countGoodStrings(int low, int high, int zero, int one) {
        int mod = 1e9 + 7;
        vector<int> f(high + 1, 0);
        f[0] = 1;
        int ans = 0;
        for (int i = 0; i <= high; i++) {
            if (i >= zero) f[i] = (f[i] + f[i-zero]) % mod;
            if (i >= one) f[i] = (f[i] + f[i-one]) % mod;
            if (i >= low) ans = (ans + f[i]) % mod;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n3\n1\n1\n
// @lcpr case=end

// @lcpr case=start
// 2\n3\n1\n2\n
// @lcpr case=end

 */

