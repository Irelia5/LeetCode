/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 * @lcpr version=30113
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
        // 问题的核心是逆向思维
        // 将问题转换为：寻找和为 s - x 的最长子串
        int ans = -1;
        int s = 0;
        for (auto num : nums) {
            s += num;
        }
        int target = s - x;
        if (target < 0) return -1;
        int sum = 0;
        for (int left = 0, right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            while (sum > target) sum -= nums[left++];
            if (sum == target) ans = max(ans, right - left + 1);
        }
        return ans == -1 ? -1 : nums.size() - ans;
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

