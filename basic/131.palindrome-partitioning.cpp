/*
 * @lc app=leetcode.cn id=131 lang=cpp
 * @lcpr version=30117
 *
 * [131] 分割回文串
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
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        int n = s.size();
        function<void(int)> dfs = [&] (int i) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j < n; ++j) {
                if (is_re(s, i, j)) {
                    path.push_back(s.substr(i, j - i + 1));
                    dfs(j + 1);
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }


    vector<vector<string>> partition1(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        int n = s.size();
        function<void(int, int)> dfs = [&] (int i, int start) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            if (i < n - 1) {
                dfs(i + 1, start);
            }
            if (is_re(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                dfs(i + 1, i + 1);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }
private:
    bool is_re(const std::string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            ++left;
            --right;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */

