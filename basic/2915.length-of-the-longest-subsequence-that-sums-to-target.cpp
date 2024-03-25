/*
 * @lc app=leetcode.cn id=2915 lang=cpp
 * @lcpr version=30119
 *
 * [2915] 和为目标值的最长子序列的长度
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
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> f(target + 1, INT_MIN);
        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int c = target; c >= 0; --c) {
                if (c >= nums[i]) f[c] = max(f[c], f[c-nums[i]] + 1);
            }
        }
        int ans = f[target];
        return ans < 0 ? -1 : ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n9\n
// @lcpr case=end

// @lcpr case=start
// [4,1,3,2,1,5]\n7\n
// @lcpr case=end

// @lcpr case=start
// [1,1,5,4,5]\n3\n
// @lcpr case=end

 */

