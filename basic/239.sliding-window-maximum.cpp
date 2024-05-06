/*
 * @lc app=leetcode.cn id=239 lang=cpp
 * @lcpr version=30122
 *
 * [239] 滑动窗口最大值
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            // 入
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            // 出
            if (i - dq.front() >= k) {
                dq.pop_front();
            }
            // 更新最大值
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,-1,-3,5,3,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

