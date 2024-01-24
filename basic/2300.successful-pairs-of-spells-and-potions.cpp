/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 * @lcpr version=30113
 *
 * [2300] 咒语和药水的成功对数
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
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
       sort(potions.begin(), potions.end());
       for (auto & n : spells) {
            long long target = (success - 1) / n;
            auto iter = upper_bound(potions.begin(), potions.end(), target);
            n = distance(iter, potions.end());
       }
       return spells;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,1,3]\n[1,2,3,4,5]\n7\n
// @lcpr case=end

// @lcpr case=start
// [3,1,2]\n[8,5,8]\n16\n
// @lcpr case=end

 */

