/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * @lcpr version=30117
 *
 * [22] 括号生成
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
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        vector<int> path;
        int m = n * 2;
        function<void(int, int)> dfs = [&] (int i, int balance) {
            if (path.size() == n) {
                string s(m, ')');
                for (auto index : path) {
                    s[index] = '(';
                }
                ans.emplace_back(s);
                return;
            }
            for (int close = 0; close <= balance; ++close) {
                path.push_back(close + i);
                dfs(i + close + 1, balance - close + 1);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }


    vector<string> generateParenthesis2(int n) {
        vector<string> ans;
        int m = 2 * n;
        string path(m , 0);
        function<void(int, int)> dfs = [&] (int i, int open) {
            if (i == m) {
                ans.emplace_back(path);
                return;
            }
            if (open < n) {
                path[i] = '(';
                dfs(i + 1, open + 1);
            }
            if (i - open < open) {
                path[i] = ')';
                dfs(i + 1, open);
            }
        };
        dfs(0, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

