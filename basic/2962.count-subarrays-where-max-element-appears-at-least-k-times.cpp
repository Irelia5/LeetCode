/*
 * @lc app=leetcode.cn id=2962 lang=cpp
 * @lcpr version=30113
 *
 * [2962] 统计最大元素出现至少 K 次的子数组
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
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int max_element = nums[0];
        for (auto num : nums) {
            max_element = max(num, max_element);
        }
        int cnt = 0;
        for (int left = 0, right = 0; right < nums.size(); ++right) {
            if (nums[right] == max_element) ++cnt;
            while (cnt == k) {
                if (nums[left++] == max_element) {
                    --cnt;
                }
            }
            ans += left;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2,3,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,4,2,1]\n3\n
// @lcpr case=end

 */

