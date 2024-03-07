/*
 * @lc app=leetcode.cn id=198 lang=cpp
 * @lcpr version=30117
 *
 * [198] 打家劫舍
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
    int rob0(vector<int>& nums) {
        int n = nums.size();
        function<int(int)> dfs = [&](int i) {
            if (i < 0) return 0;
            int res = max(dfs(i - 1), dfs(i - 2) + nums[i]);
            return res;
        };
        return dfs(n - 1);
    }
    int rob1(vector<int>& nums) {
        int n = nums.size();
        vector<int> cache (n, -1);
        function<int(int)> dfs = [&](int i) {
            if (i < 0) return 0;
            if (cache[i] != -1) return cache[i];
            int res = max(dfs(i - 1), dfs(i - 2) + nums[i]);
            cache[i] = res;
            return res;
        };
        return dfs(n - 1);
    }

    int rob2(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2, 0);
        for (int i = 0; i < n; ++i) {
            dp[i+2] = max(dp[i+1], dp[i] + nums[i]);
        }
        return dp[n+1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        int f0 = 0, f1 = 0;
        for (int i = 0; i < n; ++i) {
            int f = max(f0 + nums[i], f1);
            f0 = f1;
            f1 = f; 
        }
        return f1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9,3,1]\n
// @lcpr case=end

 */

