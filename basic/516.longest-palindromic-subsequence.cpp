/*
 * @lc app=leetcode.cn id=516 lang=cpp
 * @lcpr version=30121
 *
 * [516] 最长回文子序列
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
    int longestPalindromeSubseq1(string s) {
        int n = s.size();
        function<int(int, int)> dfs = [&](int i, int j) ->int {
            if (i > j) return 0;
            if (i == j) return 1;
            if (s[i] == s[j]) return dfs(i + 1, j - 1) + 2;
            else return max(dfs(i + 1, j), dfs(i, j - 1));
        };
        return dfs(0, n - 1);
    }

    int longestPalindromeSubseq2(string s) {
        int n = s.size();
        int f[n][n];
        memset(f, 0, sizeof f);

        for (int i = n - 1; i >= 0; --i) {
            f[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) f[i][j] = f[i + 1][j - 1] + 2;
                else f[i][j] = max(f[i + 1][j], f[i][j - 1]);
            }
        }
        return f[0][n - 1];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int f[n];
        memset(f, 0, sizeof f);
        
        for (int i = n - 1; i >= 0; --i) {
            f[i] = 1;
            int pre = 0;
            for (int j = i + 1; j < n; ++j) {
                int tmp = f[j];
                if (s[i] == s[j]) f[j] = pre + 2;
                else f[j] = max(f[j], f[j - 1]);
                pre = tmp;
            }

        }
        return f[n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "bbbab"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

