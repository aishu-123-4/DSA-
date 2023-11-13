#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(matrix[0].begin(), matrix[0].end());
        vector<int> curr(n);
        for (int i=1; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (j == 0) curr[j] = matrix[i][j] + min(dp[j], dp[j+1]);
                else if (j == n - 1) curr[j] = matrix[i][j] + min(dp[j-1], dp[j]);
                else {
                    curr[j] = min(dp[j-1], dp[j]);
                    curr[j] = matrix[i][j] + min(curr[j], dp[j+1]);
                }
            }
            dp = curr;
        }
        return *min_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution s;
    vector<vector<int>> nums = {{2,1,3},{6,5,4},{7,8,9}};
    int ans = s.minFallingPathSum(nums);
    cout << ans << endl;
    return 0;
}