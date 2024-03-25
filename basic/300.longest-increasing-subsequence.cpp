/*
 * @lc app=leetcode.cn id=300 lang=cpp
 * @lcpr version=30119
 *
 * [300] 最长递增子序列
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
    int lengthOfLIS1(vector<int>& nums) {
        int n = nums.size();
        function<int(int)> dfs = [&] (int i) {
            if (i < 0) return 0;
            int res = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    res = max(res, dfs(j));
                }
            }
            return res + 1;
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }
    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        vector<int> cache(n, -1);
        function<int(int)> dfs = [&] (int i) {
            if (i < 0) return 0;
            int& cache_val = cache[i];
            if (-1 != cache_val) return cache_val;
            int res = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    res = max(res, dfs(j));
                }
            }
            return cache_val = res + 1;
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }

    int lengthOfLIS3(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 0);
        for (int i = 0; i < n; ++i) {
            int res = 0;
            for (int j = 0; j <= i; ++j) {
                if (nums[j] < nums[i]) f[i] = max(f[i], f[j]);
            }
            f[i] += 1;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, f[i]);
        }
        return ans;
    }

    int lengthOfLIS4(vector<int>& nums) {
        vector<int> g;
        for (auto x : nums) {
            auto left = lower_bound(g.begin(), g.end(), x);
            if (left != g.end()) *left = x;
            else g.push_back(x);
        }
        return g.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        auto tail = nums.begin();
        for (auto x : nums) {
            auto left = lower_bound(nums.begin(), tail, x);
            if (left != tail) *left = x;
            else {
                *tail = x;
                advance(tail, 1);
            }
        }
        return distance(nums.begin(), tail);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,9,2,5,3,7,101,18]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7,7]\n
// @lcpr case=end

 */

