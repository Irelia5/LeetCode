/*
 * @lc app=leetcode.cn id=1771 lang=cpp
 * @lcpr version=30122
 *
 * [1771] 由子序列构造的最长回文串的长度
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
    int longestPalindrome1(string word1, string word2) {
        string word = word1 + word2;
        int n = word.size();
        function<int(int, int, int)> dfs = [&] (int i, int j, int match) ->int {
            if (i > j) return 0;
            if (i == j) return match;
            if (word[i] == word[j]) {
                int flag = (i < word1.size() && j >= word1.size()) || match;
                int val = dfs(i + 1, j - 1, flag);
                return flag ? val + 2 : val;
            } else {
                int sel1 = dfs(i + 1, j, match);
                int sel2 = dfs(i, j - 1, match);
                return max(sel1, sel2);
            }
        };
        return dfs(0, n - 1, 0);
    }

    int longestPalindrome(string word1, string word2) {
        int ans = 0;
        string word = word1 + word2;
        int n = word.size();
        int f[n][n];
        memset(f, 0, sizeof f);
        for (int i = n - 1; i >= 0; --i) {
            f[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (word[i] == word[j]) {
                    f[i][j] = f[i + 1][j - 1] + 2;
                    if (i < word1.size() && j >= word1.size()) ans = max(ans, f[i][j]);
                }
                else f[i][j] = max(f[i + 1][j], f[i][j - 1]);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "cacb"\n"cbba"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n"ab"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"bb"\n
// @lcpr case=end

 */

