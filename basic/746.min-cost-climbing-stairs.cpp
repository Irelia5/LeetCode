/*
 * @lc app=leetcode.cn id=746 lang=cpp
 * @lcpr version=30119
 *
 * [746] 使用最小花费爬楼梯
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
    int minCostClimbingStairs1(vector<int>& cost) {
        int n = cost.size();
        function<int(int)> dfs = [&] (int i) {
            if (i <= 1) return 0;
            return min(dfs(i - 1) + cost[i - 1], dfs(i - 2) + cost[i - 2]);
        };
        return dfs(n);
    }

    int minCostClimbingStairs2(vector<int>& cost) {
        int n = cost.size();
        int cache[n + 1];
        memset(cache, -1, sizeof(cache));
        function<int(int)> dfs = [&] (int i) {
            if (i <= 1) return 0;
            auto& res = cache[i];
            if (res != -1) return res;
            return res = min(dfs(i - 1) + cost[i - 1], dfs(i - 2) + cost[i - 2]);
        };
        return dfs(n);
    }

    int minCostClimbingStairs3(vector<int>& cost) {
        int n = cost.size();
        vector<int> f(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            f[i] = min(f[i-1] + cost[i-1], f[i-2] + cost[i-2]);
        }
        return f[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int f0 = 0, f1 = 0;
        for (int i = 2; i <= n; ++i) {
            int f = min(f1 + cost[i-1], f0 + cost[i-2]);
            f0 = f1;
            f1 = f;
        }
        return f1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,15,20]\n
// @lcpr case=end

// @lcpr case=start
// [1,100,1,1,1,100,1,1,100,1]\n
// @lcpr case=end

 */

