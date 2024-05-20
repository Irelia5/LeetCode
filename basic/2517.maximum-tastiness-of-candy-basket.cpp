/*
 * @lc app=leetcode.cn id=2517 lang=cpp
 * @lcpr version=30122
 *
 * [2517] 礼盒的最大甜蜜度
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
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        auto f = [&] (int d) -> int {
            int cnt = 1;
            int pre = price[0];
            for (auto p : price) {
                if (p >= pre + d) {
                    ++cnt;
                    pre = p;
                }
            }
            return cnt;
        };
        int n = price.size();
        int left = 0, right = price[n - 1] - price[0];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (f(mid) >= k) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [13,5,1,8,21,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,3,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7]\n2\n
// @lcpr case=end

 */

