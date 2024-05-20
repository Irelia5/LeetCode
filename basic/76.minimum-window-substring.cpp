/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * @lcpr version=30122
 *
 * [76] 最小覆盖子串
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
    string minWindow(string s, string t) {
        int m = s.size();
        int cnt_t[128]{}, cnt_s[128]{};
        int less = 0;
        for (auto c : t) {
            less += cnt_t[c]++ == 0;
        }
        int ans_left = -1, ans_right = m;
        for (int left = 0, right = 0; right < m; ++right) {
            char c = s[right];
            less -= ++cnt_s[c] == cnt_t[c];
            while (less == 0) {
                if (right - left < ans_right - ans_left) {
                    ans_left = left;
                    ans_right = right;
                }
                char x = s[left++];
                less += cnt_s[x]-- == cnt_t[x];
            }
        }
        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

 */

