/*
 * @lc app=leetcode.cn id=1234 lang=cpp
 * @lcpr version=30113
 *
 * [1234] 替换子串得到平衡字符串
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
    int balancedString(string s) {
        // 初始化
        int cnt['X'] {};
        
        for (auto c : s) {
            ++cnt[c];
        }
        int ans = s.size();
        int m = s.size() / 4;
        if (cnt['Q'] == m && cnt['W'] == m && cnt['E'] == m && cnt['R'] == m) return 0;
        for (int left = 0, right = 0; right < s.size(); ++right) {
            --cnt[s[right]];
            while (cnt['Q'] <= m && cnt['W'] <= m && cnt['E'] <= m && cnt['R'] <= m) {
                ans = min(ans, right - left + 1);
                ++cnt[s[left++]];
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "QWER"\n
// @lcpr case=end

// @lcpr case=start
// "QQWE"\n
// @lcpr case=end

// @lcpr case=start
// "QQQW"\n
// @lcpr case=end

// @lcpr case=start
// "QQQQ"\n
// @lcpr case=end

 */

