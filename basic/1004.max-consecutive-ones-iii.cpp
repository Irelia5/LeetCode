/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 * @lcpr version=30113
 *
 * [1004] 最大连续1的个数 III
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
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int used = 0;
        for (int left = 0, right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) ++used;
            while (used > k) {
                if (nums[left++] == 0) --used;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,0,0,0,1,1,1,1,0]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]\n3\n
// @lcpr case=end

 */

