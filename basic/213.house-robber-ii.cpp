/*
 * @lc app=leetcode.cn id=213 lang=cpp
 * @lcpr version=30117
 *
 * [213] 打家劫舍 II
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
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(nums[0] + rob(nums, 2, n - 1), rob(nums, 1, n));
    }
private:
    int rob(vector<int>& nums, int start, int end) {
        int f0 = 0, f1 = 0;
        while (start < end) {
            int f = max(f0 + nums[start], f1);
            f0 = f1;
            f1 = f;
            ++start;
        }
        return f1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

