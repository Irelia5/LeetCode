/*
 * @lc app=leetcode.cn id=209 lang=cpp
 * @lcpr version=30113
 *
 * [209] 长度最小的子数组
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
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int s = 0;
        for (int left = 0, right = 0; right < nums.size(); ++right) {
            s += nums[right];
            while (s >= target) {
                ans = min(ans, right - left + 1);
                s -= nums[left];
                ++left;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */

