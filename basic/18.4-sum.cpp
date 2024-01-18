/*
 * @lc app=leetcode.cn id=18 lang=cpp
 * @lcpr version=30113
 *
 * [18] 四数之和
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int a = 0; a < n - 3; ++a) {
            if (a > 0 && nums[a] == nums[a - 1]) continue;
            int64_t s = (int64_t)nums[a] + nums[a + 1] + nums[a + 2] + nums[a + 3];
            if (s > target) break;
            s = (int64_t)nums[a] + nums[n - 1] + nums[n - 2] + nums[n - 3];
            if (s < target) continue;
            for (int b = a + 1; b < n - 2; ++b) {
                if (b > a + 1 && nums[b] == nums[b - 1]) continue;
                int64_t s = (int64_t)nums[a] + nums[b] + nums[b + 1] + nums[b + 2];
                if (s > target) break;
                s = (int64_t)nums[a] + nums[b] + nums[n - 1] + nums[n - 2];
                if (s < target) continue;
                int c = b + 1, d = n - 1;
                while (c < d) {
                    int64_t s = (int64_t)nums[a] + nums[b] + nums[c] + nums[d];
                    if (s < target) ++c;
                    else if (s > target) --d;
                    else {
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        for (++c; c < d && nums[c] == nums[c - 1]; ++c);
                        for (--d; c < d && nums[d] == nums[d + 1]; --d);
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
// [1,0,-1,0,-2,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n8\n
// @lcpr case=end

 */

