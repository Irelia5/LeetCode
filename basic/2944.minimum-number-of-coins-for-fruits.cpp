/*
 * @lc app=leetcode.cn id=2944 lang=cpp
 * @lcpr version=30204
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
    int minimumCoins1(vector<int>& prices) {
        int n = prices.size();
        vector<int> memo((n + 1) / 2);
        function<int(int)> dfs = [&] (int i) {
            if (i >= (n + 1) / 2) return prices[i - 1];
            int& res = memo[i];
            if (res) return res;
            res = INT_MAX;
            for (int j = i + 1; j <= 2 * i + 1; j++) {
                res = min(res, dfs(j));
            }
            res += prices[i - 1];
            return res;
        };
        return dfs(1);
    }

    int minimumCoins2(vector<int>& prices) {
        int n = prices.size();
        for (int i = (n + 1) / 2 - 1; i >= 1; --i) {
            prices[i - 1] = prices[i - 1] + *min_element(prices.begin() + i, prices.begin() + i * 2 + 1);
        }
        return prices[0];
    }

    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        deque<pair<int,int>> dq;
        dq.emplace_back(n + 1, 0);
        for (int i = n; i > 0; --i) {
            while (dq.front().first > 2 * i + 1) {
                dq.pop_front();
            }
            int f = prices[i - 1] + dq.front().second;
            
            while (dq.back().second >= f) {
                dq.pop_back();
            }
            dq.emplace_back(i, f);
        }
        return dq.back().second;
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

