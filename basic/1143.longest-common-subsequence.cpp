/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 * @lcpr version=30119
 *
 * [1143] 最长公共子序列
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
    int longestCommonSubsequence1(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        function<int(int, int)> dfs = [&] (int i, int j) {
            if (i < 0 || j < 0) return 0;
            if (text1[i] == text2[j]) return dfs(i - 1, j - 1) + 1;
            else return max(dfs(i - 1, j), dfs(i, j - 1));
        };
        return dfs(n - 1, m - 1);
    }

    int longestCommonSubsequence2(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        int cache[n][m];
        memset(cache, -1, sizeof cache);
        function<int(int, int)> dfs = [&] (int i, int j) {
            if (i < 0 || j < 0) return 0;
            auto& res = cache[i][j];
            if (-1 != res) return res;
            if (text1[i] == text2[j]) return res = dfs(i - 1, j - 1) + 1;
            else return res = max(dfs(i - 1, j), dfs(i, j - 1));
        };
        return dfs(n - 1, m - 1);
    }

    int longestCommonSubsequence3(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        int f[n + 1][m + 1];
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (text1[i] == text2[j]) f[i+1][j+1] = f[i][j] + 1;
                else f[i+1][j+1] = max(f[i][j+1], f[i+1][j]);
            }
        }
        return f[n][m];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        int f[m + 1];
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; i++) {
            int pre = f[0];
            for (int j = 0; j < m; j++) {
                tmp = f[j+1];
                if (text1[i] == text2[j]) [j+1] = pre + 1;
                else f[j+1] = max(f[j+1], f[j]);
                pre = tmp;
            }
        }
        return f[m];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcde"\n"ace"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"def"\n
// @lcpr case=end

 */

