/*
 * @lc app=leetcode.cn id=4 lang=cpp
 * @lcpr version=30202
 *
 * [4] 寻找两个正序数组的中位数
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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        auto check = [&] (int i) -> bool {
            int j = (m + n - 1) / 2 + 1 - i;
            if (i == 0 || j >= n) return true;
            if (nums1[i - 1] <= nums2[j]) return true;
            return false;
        };
        int left = 0, right = min(m, (m + n - 1) / 2 + 1);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        // right nums1为切割点
        int r2 = (m + n - 1) / 2 + 1 - right;

        int Ai_1 = right < 1 ? INT_MIN : nums1[right - 1];
        int Bi_1 = r2 < 1 ? INT_MIN : nums2[r2 - 1];
        int Ai = right >= m ? INT_MAX : nums1[right];
        int Bi = r2 >= n ? INT_MAX : nums2[r2];
        return (m + n) % 2 ?
                    max(Ai_1, Bi_1) :
                    (max(Ai_1, Bi_1) + min(Ai, Bi)) / 2.0; 
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */

