/*
 * @lc app=leetcode.cn id=33 lang=cpp
 * @lcpr version=30113
 *
 * [33] 搜索旋转排序数组
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
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (is_blue(nums, mid, target)) right = mid - 1;
            else left = mid + 1;
        }
        if (left == nums.size() || nums[left] != target) return -1;
        return left;
    }

    int is_blue(vector<int>& nums, int mid, int target) {
        int end = nums[nums.size()-1];
        if (nums[mid] > end) {
            return end < target && target <= nums[mid];
        } else {
            return end < target || target <= nums[mid];
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,5,6,7,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

