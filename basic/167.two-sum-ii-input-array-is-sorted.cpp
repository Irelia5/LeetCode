/*
 * @lc app=leetcode.cn id=167 lang=cpp
 * @lcpr version=30113
 *
 * [167] 两数之和 II - 输入有序数组
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
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 有序
        // 有解
        // 每个元素仅使用一次

        int left = 0, right = numbers.size() - 1;
        while (true) {
            int s = numbers[left] + numbers[right];
            if (s == target) return {left + 1, right + 1};
            s < target ? ++left : --right;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n-1\n
// @lcpr case=end

 */

