/*
 * @lc app=leetcode.cn id=16 lang=cpp
 * @lcpr version=30113
 *
 * [16] 最接近的三数之和
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
    int threeSumClosest(vector<int>& nums, int target) {
        int ans;
        int min_diff = INT_MAX;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            int x = nums[i];
            if (i && x == nums[i - 1]) continue;
            int sum = x + nums[i + 1] + nums[i + 2];
            if (sum > target && sum - target < min_diff) {
                min_diff = sum - target;
                ans = sum;
                break;
            }
            sum = x + nums[n - 1] + nums[n - 2];
            if (sum < target && target - sum < min_diff) {
                min_diff = target - sum;
                ans = sum;
                continue;
            }

            int j = i + 1, k = n - 1;
            while (j < k) {
                int s = x + nums[j] + nums[k];
                if (s == target) {
                    return s;
                } else if (s < target) {
                    ++j;
                    if (target - s < min_diff) {
                        ans = s;
                        min_diff = target - s;
                    }
                } else {
                    --k;
                    if (s - target < min_diff) {
                        ans = s;
                        min_diff = s - target;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,2,1,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n1\n
// @lcpr case=end

 */

