/*
 * @lc app=leetcode.cn id=1626 lang=cpp
 * @lcpr version=30119
 *
 * [1626] 无矛盾的最佳球队
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
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<Team> team;
        for (int i = 0; i < n; ++i) {
            team.emplace_back(scores[i], ages[i]);
        }
        sort(team.begin(), team.end());

        vector<int> f(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (team[j].ages <= team[i].ages) f[i] = max(f[i], f[j]);
            }
            f[i] += team[i].scores;
        }
        return *max_element(f.begin(), f.end());
    }

    struct Team {
        int scores;
        int ages;
        Team(int scores, int ages)
            : scores(scores)
            , ages(ages) {}
        bool operator < (const Team& rhs) const {
            if (scores != rhs.scores) return scores < rhs.scores;
            else return ages < rhs.ages;
        }
    };
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5,10,15]\n[1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,5]\n[2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5]\n[8,9,10,1]\n
// @lcpr case=end

 */

