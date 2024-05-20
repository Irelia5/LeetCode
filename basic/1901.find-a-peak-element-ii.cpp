/*
 * @lc app=leetcode.cn id=1901 lang=cpp
 * @lcpr version=30122
 *
 * [1901] 寻找峰值 II
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
    int findMaxIndex(vector<int>& row) {
        auto iter = max_element(row.begin(), row.end());
        return distance(row.begin(), iter);
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();

        int low = 0, high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row_max_index = findMaxIndex(mat[mid]);
            int next = mid + 1 < m ? mat[mid + 1][row_max_index] : -1;
            if (mat[mid][row_max_index] < next) low = mid + 1;
            else high = mid - 1;
        }
        return {low, findMaxIndex(mat[low])};

    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[10,20,15],[21,30,14],[7,16,32]]\n
// @lcpr case=end

 */

