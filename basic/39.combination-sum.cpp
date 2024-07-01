/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30202
 *
 * [39] 组合总和
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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = candidates.size();
        function<void(int, int)> dfs = [&](int i, int d) {
            if (d == 0) {
                ans.push_back(path);
                return;
            }
            if (d < 0) return;
            for (int j = i; j < n; ++j) {
                path.push_back(candidates[j]);
                dfs(j, d - candidates[j]);
                path.pop_back();
            }
        };
        dfs(0, target);
        return ans;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

