/*
 * @lc app=leetcode.cn id=1039 lang=cpp
 * @lcpr version=30121
 *
 * [1039] 多边形三角剖分的最低得分
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
    // time limt exceeded
    int minScoreTriangulation1(vector<int>& values) {
        int n = values.size();
        function<int(int, int)> dfs = [&] (int i, int j) {
            if (j == i + 1) return 0;
            int res = INT_MAX;
            for (int k = i + 1; k < j; ++k) {
                res = min(res, dfs(i, k) + dfs(k, j) + values[i] * values[j] * values[k]);
            }
            return res;
        };
        return dfs(0, n - 1);
    }

    int minScoreTriangulation2(vector<int>& values) {
        int n = values.size();
        int cache [n][n];
        memset(cache, -1, sizeof cache);
        function<int(int, int)> dfs = [&] (int i, int j) {
            if (j == i + 1) return 0;
            auto& val = cache[i][j];
            if (val != -1) return val;
            int res = INT_MAX;
            for (int k = i + 1; k < j; ++k) {
                res = min(res, dfs(i, k) + dfs(k, j) + values[i] * values[j] * values[k]);
            }
            return val = res;
        };
        return dfs(0, n - 1);
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        int f[n][n];
        memset(f, 0, sizeof f);
        for (int i = n - 3; i >= 0; --i) {
            for (int j = i + 2; j < n; ++j) {
                int res = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    res = min(res, f[i][k] + f[k][j] + values[i] * values[j] * values[k]);
                }
                f[i][j] = res;
            }
        }
        return f[0][n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,7,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,1,4,1,5]\n
// @lcpr case=end

 */

