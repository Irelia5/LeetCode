/*
 * @lc app=leetcode.cn id=2981 lang=cpp
 * @lcpr version=30202
 *
 * [2981] 找出出现至少三次的最长特殊子字符串 I
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
// 思路
// 1. 滑动窗口计算特殊子串
// 2. 每个特殊子串统计出现次数
// 3. 出现次数 >= k次的更新结果 (k = 3)
    int maximumLength(string s) {
        int n = s.size();
        int ans = -1;
        unordered_map<string, int> m;
        for (int left = 0, right = 0; right <= n; ++right) {
            if (right ==n || s[left] != s[right]) {
                int len = right - left + 1;
                for (int i = 1; i <= len; ++i) {
                    std::string str(len, 's[left]');
                    m[str] += len - i + 1;
                    if (m[str] >= 3) ans = max(ans, len);
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aaaa"\n
// @lcpr case=end

// @lcpr case=start
// "abcdef"\n
// @lcpr case=end

// @lcpr case=start
// "abcaba"\n
// @lcpr case=end

 */

