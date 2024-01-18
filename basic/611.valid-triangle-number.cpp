/*
 * @lc app=leetcode.cn id=611 lang=cpp
 * @lcpr version=30113
 *
 * [611] 有效三角形的个数
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
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int k = 2; k < nums.size(); ++k) {
            int i = 0, j = k - 1;
            while (i < j) {
                int s = nums[i] + nums[j];
                if (s <= nums[k]) ++i;
                else {
                    ans += j - i;
                    --j;
                    
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,3,4]\n
// @lcpr case=end

 */

