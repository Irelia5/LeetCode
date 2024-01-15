#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            int x = nums[i];
            if (i > 0 && x == nums[i-1]) continue;
            if (x + nums[i+1] + nums[i+2] > 0) break;
            if (x + nums[n-1] + nums[n-2] < 0) continue;
            int j = i + 1, k = n - 1;
            while (j < k) {
                int s = x + nums[j] + nums[k];
                if (s < 0) ++j;
                else if (s > 0) --k;
                else {
                    ans.push_back({x, nums[j], nums[k]});
                    for (++j; j < k && nums[j] == nums[j-1]; ++j);
                    for (--k; j < k && nums[k] == nums[k+1]; --k);
                }
            }
        }
        return ans;
    }
};