/*
 * @lc app=leetcode.cn id=1671 lang=cpp
 * @lcpr version=30119
 *
 * [1671] 得到山形数组的最少删除次数
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
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 0); // 递增子序列长度
        vector<int> g;
        for (int i = 0; i < n - 1; ++i) {
            int x = nums[i];
            auto iter = lower_bound(g.begin(), g.end(), x);
            pre[i] = distance(g.begin(), iter) + 1;
            if (iter != g.end()) *iter = x;
            else g.push_back(x);
        }
        g.clear();
        vector<int> suf(n, 0); // 递减子序列长度
        for (int i = n - 1; i > 0; --i) {
            int x = nums[i];
            auto iter = lower_bound(g.begin(), g.end(), x);
            suf[i] = distance(g.begin(), iter) + 1;
            if (iter != g.end()) *iter = x;
            else g.push_back(x);
        }
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (suf[i] >= 2 && pre[i] >= 2) ans = max(ans, suf[i] + pre[i] - 1);
        }
        return n - ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,1,5,6,2,3,1]\n
// @lcpr case=end

 */

