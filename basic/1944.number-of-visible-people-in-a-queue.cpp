/*
 * @lc app=leetcode.cn id=1944 lang=cpp
 * @lcpr version=30122
 *
 * [1944] 队列中可以看到的人数
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
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            int h = heights[i];
            while (!st.empty() && h > heights[st.top()]) {
                st.pop();
                ans[i]++;
            }
            if (!st.empty()) ans[i]++;
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,6,8,5,11,9]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,2,3,10]\n
// @lcpr case=end

 */

