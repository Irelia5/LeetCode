/*
 * @lc app=leetcode.cn id=2398 lang=cpp
 * @lcpr version=30122
 *
 * [2398] 预算内的最多机器人数目
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
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        // 前缀和
        vector<long long> s(n + 1);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = runningCosts[i] + s[i];
        }

        int ans = 0;
        deque<int> dq;
        for (int left = 0, right = 0; right < n; ++right) {
            // 入
            while (!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[right]) {
                dq.pop_back();
            }
            dq.push_back(right);
            // 出
            while (!dq.empty() && chargeTimes[dq.front()] + (right - left + 1) * (s[right + 1] - s[left]) > budget) {
                if (dq.front() == left) dq.pop_front();
                ++left;
            }
            // 更新最大值
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,6,1,3,4]\n[2,1,3,4,5]\n25\n
// @lcpr case=end

// @lcpr case=start
// [11,12,19]\n[10,8,7]\n19\n
// @lcpr case=end

 */

