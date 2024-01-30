/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 * @lcpr version=30114
 *
 * [1658] 将 x 减到 0 的最小操作数
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
    int minOperations(vector<int>& nums, int x) {
        // 将问题转化为找最长子串, 满足字串和为 sum - x
        // 因为子串可能不存在, 初始result = -1
        int max_len = -1;
        int sum = 0;
        std::for_each(nums.begin(), nums.end(), [&sum](const auto n) {
            sum += n;
        });
        int target = sum - x;
        int s = 0;
        int n = nums.size();
        for (int left = 0, right = 0; right < n; ++right) {
            s += nums[right];
            // nums元素均大于0(该场景使用滑动窗口的前置条件)
            while (s > target && left <= right) s -= nums[left++];
            if (s == target) max_len = max(max_len, right - left + 1);
        }
        return max_len == -1 ? -1 : n - max_len;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,4,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [5,6,7,8,9]\n4\n
// @lcpr case=end

// @lcpr case=start
// [3,2,20,1,1,3]\n10\n
// @lcpr case=end

 */

