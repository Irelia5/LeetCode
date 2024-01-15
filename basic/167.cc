// 两数之和 II - 输入有序数组

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (true) {
            int s = numbers[left] + numbers[right];
            if (s == target) return {left + 1, right + 1};
            s < target ? ++left : --right;
        }
    }
};