#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int sol_idx = n-1;

        vector<int> ans(n);

        while (start < end) {
            if (abs(nums[start]) > abs(nums[end])) {
                ans[sol_idx--] = nums[start] * nums[start];
                start++;
            } else {
                ans[sol_idx--] = nums[end] * nums[end];
                end--;
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> ans = s.sortedSquares(nums);
    for (auto a: ans) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}