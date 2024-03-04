/*
 * @lc app=leetcode.cn id=77 lang=cpp
 * @lcpr version=30117
 *
 * [77] 组合
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
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int)> dfs = [&] (int i) {
            int count = k - path.size();
            if (count == 0) {
                ans.emplace_back(path);
                return;
            }
            if (i > count) dfs(i - 1);
            path.push_back(i);
            dfs(i - 1);
            path.pop_back();
        };
        dfs(n);
        return ans;
    }

    vector<vector<int>> combine1(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int)> dfs = [&] (int i) {
            int count = k - path.size();
            if (count == 0) {
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j >= count; --j) {
                path.push_back(j);
                dfs(j - 1);
                path.pop_back();
            }
        };
        dfs(n);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

