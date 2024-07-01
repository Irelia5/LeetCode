/*
 * @lc app=leetcode.cn id=377 lang=cpp
 * @lcpr version=30202
 *
 * [377] 组合总和 Ⅳ
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
    int combinationSum41(vector<int>& nums, int target) {
        int n = nums.size();
        int cache[target + 1];
        memset(cache, -1, sizeof cache);
        function<int(int)> dfs = [&] (int t) {
            if (t < 0) return 0;
            if (t == 0) return 1;
            auto& res = cache[t];
            if (res != -1) return res;
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += dfs(t - nums[i]);
            }
            return res = sum;
        };
        
        return dfs(target);
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned> f(target + 1);
        f[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (auto num : nums) {
                if (i >= num) f[i] += f[i - num];
            }
        }
        return f[target];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [9]\n3\n
// @lcpr case=end

 */

