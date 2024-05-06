/*
 * @lc app=leetcode.cn id=901 lang=cpp
 * @lcpr version=30122
 *
 * [901] 股票价格跨度
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
class StockSpanner {
public:
    StockSpanner() {

    }
    
    int next(int price) {
        _vec.push_back(price);
        int n = _vec.size();
        while (!_st.empty() && price >= _vec[_st.top()]) {
            _st.pop();
        }
        int ans = 0;
        if (_st.empty()) {
            ans = n;
        } else {
            ans = n - _st.top() - 1;
        }
         _st.push(n - 1);
        
        return ans;

    }
private:
    stack<int> _st;
    vector<int> _vec;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end



/*
// @lcpr case=start
// ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"][[], [100], [80], [60], [70], [60], [75], [85]]\n
// @lcpr case=end

 */

