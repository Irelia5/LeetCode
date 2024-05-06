/*
 * @lc app=leetcode.cn id=862 lang=cpp
 * @lcpr version=30122
 *
 * [862] 和至少为 K 的最短子数组
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
    int shortestSubarray(vector<int>& nums, int k) {
        // 前缀和
        int n = nums.size();
        vector<long long> s(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }

        int ans = INT_MAX;
        deque<int> dq;
        for (int i = 0; i < n; ++i) {
            // 入
            while (!dq.empty() && s[dq.back()] >= s[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            // 出
            while (!dq.empty() && s[i + 1] - s[dq.front()] >= k) {
                ans = min(ans, i - dq.front() + 1);
                dq.pop_front();
            }
            // 更新结果
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n4\n
// @lcpr case=end

// @lcpr case=start
// [2,-1,2]\n3\n
// @lcpr case=end

 */

