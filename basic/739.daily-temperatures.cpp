/*
 * @lc app=leetcode.cn id=739 lang=cpp
 * @lcpr version=30122
 *
 * [739] 每日温度
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
    vector<int> dailyTemperatures1(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            int t = temperatures[i];
            while (!st.empty() && t >= temperatures[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            int t = temperatures[i];
            while (!st.empty() && t > temperatures[st.top()]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [73,74,75,71,69,72,76,73]\n
// @lcpr case=end

// @lcpr case=start
// [30,40,50,60]\n
// @lcpr case=end

// @lcpr case=start
// [30,60,90]\n
// @lcpr case=end

 */

