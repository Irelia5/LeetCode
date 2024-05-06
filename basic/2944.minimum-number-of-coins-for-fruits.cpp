/*
 * @lc app=leetcode.cn id=2944 lang=cpp
 * @lcpr version=30122
 *
 * [2944] 购买水果需要的最少金币数
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
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        function<int(int, int)> dfs = [&] (int i, int free) {
            if (i == 0) return prices[i];
            if (!free) return dfs(i - 1, 1);
            return max(dfs(i - 1, 0), dfs(i - 1, 1));
        };
        return dfs(n - 1, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,10,1,1]\n
// @lcpr case=end

 */

