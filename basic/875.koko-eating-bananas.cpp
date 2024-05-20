/*
 * @lc app=leetcode.cn id=875 lang=cpp
 * @lcpr version=30122
 *
 * [875] 爱吃香蕉的珂珂
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
    int minEatingSpeed(vector<int>& piles, int h) {
        auto check = [&] (int k) -> bool {
            int s = piles.size();
            for (auto pile : piles) {
                s += (pile - 1) / k;
                if (s > h) return false;
            }
            return true;
        };
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while (left <= right) {
            int k = left + (right - left) / 2;
            if (check(k)) {
                right = k - 1;
            } else {
                left = k + 1;
            }
        }
        return left;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,6,7,11]\n8\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n5\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n6\n
// @lcpr case=end

 */

