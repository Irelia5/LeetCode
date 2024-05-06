/*
 * @lc app=leetcode.cn id=1696 lang=cpp
 * @lcpr version=30122
 *
 * [1696] 跳跃游戏 VI
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
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> f(n, 0);
        f[0] = nums[0];
        deque<int> dq{0};
        for (int i = 1; i < n; ++i) {
            // 出
            while (!dq.empty() && i - dq.front() > k) {
                dq.pop_front();
            }
            f[i] = nums[i] + f[dq.front()];
            // 入
            while (!dq.empty() && f[i] >= f[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return f[n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,-1,-2,4,-7,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [10,-5,-2,4,0,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,-5,-20,4,-1,3,-6,-3]\n2\n
// @lcpr case=end

 */

