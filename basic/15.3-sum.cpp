/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=30113
 *
 * [15] 三数之和
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 三元数组顺序不重要 
        // i < j < k
        // 答案中不可以包含重复的三元组
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 跳过重复元素
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
            if (nums[i] + nums[n - 1] + nums[n - 2] < 0) continue;
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    ++j;
                    //for (++j; j < k && nums[j] == nums[j - 1]; ++j);
                } else if (sum > 0) {
                    --k;
                    // for (--k; j < k && nums[k] == nums[k + 1]; --k);
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    for (++j; j < k && nums[j] == nums[j - 1]; ++j); // 跳过重复元素
                    for (--k; j < k && nums[k] == nums[k + 1]; --k); // 跳过重复元素
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */

