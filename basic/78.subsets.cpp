/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30117
 *
 * [78] 子集
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
    vector<vector<int>> subsets1(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.empty()) return ans;
        int n = nums.size();
        vector<int> path;
        function<void(int)> dfs = [&] (int i) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            dfs(i + 1);
            path.push_back(nums[i]);
            dfs(i + 1);
            path.pop_back();
        };
        dfs(0);
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.empty()) return ans;
        int n = nums.size();
        vector<int> path;
        function<void(int)> dfs = [&] (int i) {
            ans.push_back(path);
            if (i == n) return;
            for (int j = i; j < n; ++j) {
                path.push_back(nums[j]);
                dfs(j + 1);
                path.pop_back();
            }
        };
        dfs(0);
        return ans;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

