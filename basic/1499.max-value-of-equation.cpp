/*
 * @lc app=leetcode.cn id=1499 lang=cpp
 * @lcpr version=30122
 *
 * [1499] 满足不等式的最大值
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
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        deque<pair<int, int>> dq;
        int ans = INT_MIN;

        for (auto &p : points) {
            int x = p[0];
            int y = p[1];
            while (!dq.empty() && x - dq.front().first > k) {
                dq.pop_front();
            }
            if (!dq.empty()) {
                ans = max(ans, x + y + dq.front().second - dq.front().first);
            }
            while (!dq.empty() && y - x >= dq.back().second - dq.back().first) {
                dq.pop_back();
            }
            dq.emplace_back(x, y);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,0],[5,10],[6,-10]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[3,0],[9,2]]\n3\n
// @lcpr case=end

 */

