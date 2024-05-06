/*
 * @lc app=leetcode.cn id=1000 lang=cpp
 * @lcpr version=30122
 *
 * [1000] 合并石头的最低成本
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
    int mergeStones1(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1)) return -1;
        // 前缀和
        vector<int> s(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + stones[i];
        }

        function<int(int, int, int)> dfs = [&](int i, int j, int p) {
            if (p == 1) return i == j ? 0 : dfs(i, j, k) + s[j + 1] - s[i];
            int res = INT_MAX;
            for (int m = i; m < j; m += k - 1) {
                res = min(res, dfs(i, m, 1) + dfs(m + 1, j, p - 1));
            }
            return res;
        };
        return dfs(0, n -  1, 1);
    }

    int mergeStones2(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1)) return -1;
        // 前缀和
        vector<int> s(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + stones[i];
        }

        int cache[n][n][k + 1];
        memset(cache, -1, sizeof cache);
        function<int(int, int, int)> dfs = [&](int i, int j, int p) {
            auto& res = cache[i][j][p];
            if (-1 != res) return res;
            if (p == 1) return res = i == j ? 0 : dfs(i, j, k) + s[j + 1] - s[i];
            res = INT_MAX;
            for (int m = i; m < j; m += k - 1) {
                res = min(res, dfs(i, m, 1) + dfs(m + 1, j, p - 1));
            }
            return res;
        };
        return dfs(0, n -  1, 1);
    }

    int mergeStones3(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1)) return -1;
        // 前缀和
        vector<int> s(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + stones[i];
        }
        int cache[n][n];
        memset(cache, -1, sizeof cache);
        function<int(int, int)> dfs = [&](int i, int j) {
            if (i == j) return 0;
            int& res = cache[i][j];
            if (res != -1) return res;
            res = INT_MAX;
            for (int m = i; m < j; m += k - 1) {
                res = min(res, dfs(i, m) + dfs(m + 1, j));
            }
            if ((j - i) % (k - 1) == 0) {
                res += s[j + 1] - s[i];
            }
            return res;
        };
        return dfs(0, n - 1);
    }

    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1)) return -1;
        // 前缀和
        vector<int> s(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + stones[i];
        }
        int f[n][n];
        memset(f, 0x3f, sizeof f);
        for (int i = n - 1; i >= 0; i--) {
            f[i][i] = 0;
            for (int j = i + 1; j < n; ++j) {
                for (int m = i; m < j; m += k - 1) {
                    f[i][j] = min(f[i][j], f[i][m] + f[m + 1][j]);
                }
                if ((j - i) % (k - 1) == 0) {
                    f[i][j] += s[j + 1] - s[i];
                }
            }
        }
        return f[0][n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,4,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [3,5,1,2,6]\n3\n
// @lcpr case=end

 */

