/*
 * @lc app=leetcode.cn id=1793 lang=cpp
 * @lcpr version=30122
 *
 * [1793] 好子数组的最大分数
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
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left (n, -1);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            int h = nums[i];
            while (!st.empty() && h <= nums[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }
        st = stack<int> ();
        vector<int> right (n, n);
        for (int i = n - 1; i >= 0; --i) {
            int h = nums[i];
            while (!st.empty() && h <= nums[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int h = nums[i], l = left[i], r = right[i];
            if (l < k && k < r) {
                ans = max(ans, h * (r - l - 1));
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,3,7,4,5]\n3\n
// @lcpr case=end

// @lcpr case=start
// [5,5,4,5,4,1,1,1]\n0\n
// @lcpr case=end

 */

