/*
 * @lc app=leetcode.cn id=70 lang=cpp
 * @lcpr version=30119
 *
 * [70] 爬楼梯
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
    int climbStairs1(int n) {
        if (n <= 1) return 1;
        return climbStairs1(n - 1) + climbStairs1(n - 2);
    }

    int climbStairs2(int n) {
        vector<int> cache(n + 1, 0);
        function<int(int)> dfs = [&](int i) {
            if (i <= 1) return 1;
            auto& res = cache[i];
            if (res) return res;
            return res = dfs(i- 1) + dfs(i - 2);
        };
        return dfs(n);
    }

    int climbStairs3(int n) {
        vector<int> cache(n + 1, 0);
        cache[0] = 1, cache[1] = 1;
        for (int i = 2; i <= n; ++i) {
            cache[i] = cache[i - 2] + cache[i - 1];
        }
        return cache[n];
    }

    int climbStairs(int n) {
        int f_0 = 1, f_1 = 1;
        for (int i = 2; i <= n; ++i) {
            int new_f = f_0 + f_1;
            f_0 = f_1;
            f_1 = new_f;
        }
        return f_1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

