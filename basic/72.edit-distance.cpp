/*
 * @lc app=leetcode.cn id=72 lang=cpp
 * @lcpr version=30119
 *
 * [72] 编辑距离
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
    int minDistance1(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        function<int(int, int)> dfs = [&] (int i, int j) {
            if (i < 0) return j + 1;
            if (j < 0) return i + 1;
            if (word1[i] == word2[j]) return dfs(i - 1, j - 1);
            return min(min(dfs(i, j - 1), dfs(i - 1, j)), dfs(i - 1, j - 1)) + 1;
        };
        return dfs(n - 1, m - 1);
    }

    int minDistance2(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if (!m || !n) return m | n;
        int cache[n][m];
        memset(cache, -1, sizeof cache);
        function<int(int, int)> dfs = [&] (int i, int j) {
            if (i < 0) return j + 1;
            if (j < 0) return i + 1;
            int& res = cache[i][j];
            if (-1 != res) return res;
            if (word1[i] == word2[j]) return res = dfs(i - 1, j - 1);
            return res = min(min(dfs(i, j - 1), dfs(i - 1, j)), dfs(i - 1, j - 1)) + 1;
        };
        return dfs(n - 1, m - 1);
    }

    int minDistance3(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if (!m || !n) return m | n;
        // 初始化
        int f[n + 1][m + 1];
        memset(f, 0x3f, sizeof f);
        for (int j = 0; j <= m; ++j) {
            f[0][j] = j;
        }
        for (int i = 0; i <= n; ++i) {
            f[i][0] = i;
        }
        // 状态计算
        for (int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if (word1[i] == word2[j]) f[i + 1][j + 1] = f[i][j];
                else f[i + 1][j + 1] = min(min(f[i + 1][j], f[i][j + 1]), f[i][j]) + 1;
            }
        }
        return f[n][m];
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if (!m || !n) return m | n;
        // 初始化
        int f[m + 1];
        memset(f, 0, sizeof f);
        for (int j = 0; j <= m; ++j) {
            f[j] = j;
        }
        // 状态计算
        for (int i = 0; i < n; ++i) {
            int pre = f[0];
            f[0] = i + 1;
            for(int j = 0; j < m; ++j) {
                int tmp = f[j + 1];
                if (word1[i] == word2[j]) f[j + 1] = pre;
                else f[j + 1] = min(min(f[j], f[j + 1]), pre) + 1;
                pre = tmp;
            }
        }
        return f[m];
    }

};
// @lc code=end



/*
// @lcpr case=start
// "horse"\n"ros"\n
// @lcpr case=end

// @lcpr case=start
// "intention"\n"execution"\n
// @lcpr case=end

 */

