/*
 * @lc app=leetcode.cn id=2958 lang=cpp
 * @lcpr version=30122
 *
 * [2958] 最多 K 个重复元素的最长子数组
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
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int ans = 0;
        int n = nums.size();
        for (int left = 0, right = 0; right < n; ++right) {
            ++cnt[nums[right]];
            while (cnt[nums[right]] > k) {
                --cnt[nums[left]];
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,1,2,3,1,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,2,1,2,1,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,5,5,5,5,5,5]\n4\n
// @lcpr case=end

 */

