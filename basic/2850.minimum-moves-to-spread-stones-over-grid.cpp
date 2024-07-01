/*
 * @lc app=leetcode.cn id=2850 lang=cpp
 * @lcpr version=30202
 *
 * [2850] 将石头分散到网格图的最少移动次数
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
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int,int>> from, to;
        int n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    for (int k = 1; k < grid[i][j]; ++k) {
                        from.emplace_back(i, j);
                    }
                } else {
                    to.emplace_back(i, j);
                }
            }
        }
        // 枚举全排列
        int ans = INT_MAX;
        do {
            int total = 0;
            for (int i = 0; i < from.size(); ++i) {
                total += abs(from[i].first - to[i].first) + abs(from[i].second - to[i].second);
            }
            ans = min(ans, total);
        } while (next_permutation(from.begin(), from.end()));
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,0],[1,1,1],[1,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,0],[1,0,0],[1,0,3]]\n
// @lcpr case=end

 */

