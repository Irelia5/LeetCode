/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=30113
 *
 * [42] 接雨水
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
    int trap(vector<int>& height) {
        // 第i个格子的蓄水量取决于 min (pre_max, suf_max) 
        // 也就是说, 如果能确定上面的值(找到 min), 该格子就完成了计算, 可以跳过
        // 每次缩减 已计算的格子
        // 时间复杂度 O(N)
        int ans = 0;
        int pre_max = 0, suf_max = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            pre_max = max(pre_max, height[left]);
            suf_max = max(suf_max, height[right]);
            if (pre_max < suf_max) {
                ans += pre_max - height[left];
                ++left;
            } else {
                ans += suf_max - height[right];
                --right;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */

