/*
 * @lc app=leetcode.cn id=494 lang=cpp
 * @lcpr version=30119
 *
 * [494] 目标和
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
    int findTargetSumWays1(vector<int>& nums, int target) {
        int n = nums.size();
        for (auto i : nums) target += i;
        if (target < 0 || target % 2 != 0) return 0;
        target /= 2;
        int cache[n][target + 1];
        memset(cache, -1, sizeof(cache));
        function<int(int, int)> dfs = [&] (int i, int c) {
            if (i < 0) {
                return c == 0 ? 1 : 0;
            }
            int& res = cache[i][c];
            if (res != -1) return res;
            if (c < nums[i]) return res = dfs(i - 1, c);
            return res = dfs(i - 1, c) + dfs(i - 1, c - nums[i]);
        };
        return dfs(n - 1, target);
    }

    int findTargetSumWays2(vector<int>& nums, int target) {
        for (auto i : nums) target += i;
        if (target < 0 || target % 2 != 0) return 0;
        target /= 2;
        int n = nums.size(), f[n + 1][target + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int c = 0; c <= target; ++c) {
                if (c < nums[i]) f[i + 1][c] = f[i][c];
                else f[i + 1][c] = f[i][c] + f[i][c - nums[i]];
            }
        }
        return f[n][target];
    }

    int findTargetSumWays3(vector<int>& nums, int target) {
        for (auto i : nums) target += i;
        if (target < 0 || target % 2 != 0) return 0;
        target /= 2;
        int n = nums.size(), f[2][target + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int c = 0; c <= target; ++c) {
                if (c < nums[i]) f[(i + 1) % 2][c] = f[i % 2][c];
                else f[(i + 1) % 2][c] = f[i % 2][c] + f[i % 2][c - nums[i]];
            }
        }
        return f[n % 2][target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        for (auto i : nums) target += i;
        if (target < 0 || target % 2 != 0) return 0;
        target /= 2;
        int f[target + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (auto x : nums) {
            for (int c = target; c >= x; --c) {
                f[c] = f[c] + f[c - x];
            }
        }
        return f[target];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,1,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

