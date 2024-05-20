/*
 * @lc app=leetcode.cn id=2302 lang=cpp
 * @lcpr version=30122
 *
 * [2302] 统计得分小于 K 的子数组数目
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
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<long long> sum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }
        long long ans = 0;
        long long score = 0;
        for (int left = 0, right = 0; right < n; ++right) {
            while ((sum[right + 1] - sum[left]) * (right - left + 1) >= k) {
                ++left;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,4,3,5]\n10\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n5\n
// @lcpr case=end

 */

