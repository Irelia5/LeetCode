/*
 * @lc app=leetcode.cn id=2187 lang=cpp
 * @lcpr version=30122
 *
 * [2187] 完成旅途的最少时间
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
    long long minimumTime(vector<int>& time, int totalTrips) {
        auto check = [&] (long long x) -> bool {
            long long s = 0;
            for (auto t : time) {
                s += x / t;
                if (s >= totalTrips) return true;
            }
            return false;
        };
        long long min_t = ranges::min(time);
        long long left = min_t; // 循环不变量：check(left) 恒为 false
        long long right = totalTrips * min_t; // 循环不变量：check(right) 恒为 true
        while (left <= right) {
            long long x = left + (right - left) / 2;
            if (check(x)) {
                right = x - 1;
            } else {
                left = x + 1;
            }
        }
        return left;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

