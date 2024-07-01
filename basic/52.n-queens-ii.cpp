/*
 * @lc app=leetcode.cn id=52 lang=cpp
 * @lcpr version=30202
 *
 * [52] N 皇后 II
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
    int totalNQueens(int n) {
        int ans = 0;
        vector<int> col(n, 0);
        vector<int> l1(2*n, 0);
        vector<int> l2(2*n, 0);
        function<void(int)> dfs = [&] (int i) {
            if (i == n) {
                ++ans;
                return;
            }
            for (int j = 0; j < n; ++j) {
                // 放置通过
                if (!col[j] && !l1[i + j] && !l2[j - i + n]) {
                    col[j] = 1;
                    l1[i + j] = 1;
                    l2[j - i + n] = 1;
                    dfs(i + 1);
                    col[j] = 0;
                    l1[i + j] = 0;
                    l2[j - i + n] = 0;
                }
            }
        };
        dfs(0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

