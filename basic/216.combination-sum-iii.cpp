/*
 * @lc app=leetcode.cn id=216 lang=cpp
 * @lcpr version=30117
 *
 * [216] 组合总和 III
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
    vector<vector<int>> combinationSum3A(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int, int)> dfs = [&] (int i, int t) {
            int d = k - path.size();
            if (t < 0) return;
            if (t > (2 * i + d - 1)*d / 2) return;
            if (d == 0) {
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j >= d; --j) {
                path.push_back(j);
                dfs(j - 1, t - j);
                path.pop_back();
            }
        };
        dfs(9, n);
        return ans;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int, int)> dfs = [&] (int i, int t) {
            int d = k - path.size();
            if (i < d) return;
            if (t < 0) return;
            if (t > (2 * i + d - 1)*d / 2) return;
            if (d == 0) {
                ans.emplace_back(path);
                return;
            }
            dfs(i - 1, t);
            path.push_back(i);
            dfs(i - 1, t - i);
            path.pop_back();
        };
        dfs(9, n);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n9\n
// @lcpr case=end

// @lcpr case=start
// 4\n1\n
// @lcpr case=end

 */

