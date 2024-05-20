/*
 * @lc app=leetcode.cn id=2861 lang=cpp
 * @lcpr version=30122
 *
 * [2861] 最大合金数
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
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans = 0;
        for (auto machine : composition) {

            auto check = [&] (long long x) -> bool {
                long long costed = 0;
                for (int i = 0; i < n; ++i) {
                    if (stock[i] < machine[i] * x) {
                        costed += (x * machine[i] - stock[i]) * cost[i];
                        if (costed > budget) return false;
                    }
                    
                }
                return true;
            };
            int left = 0;
            int right = ranges::min(stock) + budget;
            while (left <= right) {
                int x = left + (right - left) / 2;
                if (check(x)) {
                    left = x + 1;
                } else {
                    right = x - 1;
                }
            }
            ans = max(ans, right);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n2\n15\n[[1,1,1],[1,1,10]]\n[0,0,0]\n[1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n15\n[[1,1,1],[1,1,10]]\n[0,0,100]\n[1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// 2\n3\n10\n[[2,1],[1,2],[1,1]]\n[1,1]\n[5,5]\n
// @lcpr case=end

 */

