 /*
 * @lc app=leetcode.cn id=416 lang=cpp
 * @lcpr version=30203
 *
 * [416] 分割等和子集
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
    // dfs(i, t) = dfs(i - 1, t - nums[i]) || dfs(i - 1, t)
    // i < 0 -> t == 0
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums) sum += num;
        if (sum % 2) return false;
        sum /= 2;

        int f[sum + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int t = sum; t >= 0; --t) {
                if (t >= nums[i]) f[t] = f[t - nums[i]] || f[t];
            }
        }
        return f[sum];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,5,11,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5]\n
// @lcpr case=end

 */

