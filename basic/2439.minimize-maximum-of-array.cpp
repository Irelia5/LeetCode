/*
 * @lc app=leetcode.cn id=2439 lang=cpp
 * @lcpr version=30122
 *
 * [2439] 最小化数组中的最大值
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
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> s(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        
        auto check = [&](long long x) -> bool {
            for (int i = 0; i < n; ++i) {
                if (s[i + 1] > x * (i + 1)) return false;
            }
            return true;
        };

        int left = ranges::min(nums);
        int right = ranges::max(nums);
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
// [3,7,1,6]\n
// @lcpr case=end

// @lcpr case=start
// [10,1]\n
// @lcpr case=end

 */

