/*
 * @lc app=leetcode.cn id=154 lang=cpp
 * @lcpr version=30113
 *
 * [154] 寻找旋转排序数组中的最小值 II
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
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 2;
        int end = nums.size() - 1;
        while (left <= right && end > 0) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == nums[end]) {
                end--;
            } else if (nums[mid] < nums[end]) right = mid - 1;
            else left = mid + 1;
        }
        return nums[left];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,0,1]\n
// @lcpr case=end

 */

