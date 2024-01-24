/*
 * @lc app=leetcode.cn id=275 lang=cpp
 * @lcpr version=30113
 *
 * [275] H 指数 II
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
    int hIndex(vector<int>& citations) {
        // 虚构一个[0, n]的数组, 表示h的结果
        int left = 1, right = citations.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid <= citations[citations.size() - mid]) left = mid + 1;
            else right = mid - 1;
        }
        return left - 1;
    }
    // 不虚构结果数组, 直接通过推导在原数组上做
    int hIndex2(vector<int>& citations) {
        int left = 0, right = citations.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= citations.size() - mid) right = mid - 1;
            else left = mid + 1;
        }
        return citations.size() - left;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,3,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,100]\n
// @lcpr case=end

 */

