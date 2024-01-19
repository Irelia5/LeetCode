/*
 * @lc app=leetcode.cn id=713 lang=cpp
 * @lcpr version=30113
 *
 * [713] 乘积小于 K 的子数组
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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int m = 1;
        for (int left = 0, right = 0; right < nums.size(); ++right) {
            m *= nums[right];
            while (m >= k && left <= right) {
                m /= nums[left];
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
// [10,5,2,6]\n100\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n0\n
// @lcpr case=end

 */

