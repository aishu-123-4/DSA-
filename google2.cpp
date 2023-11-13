#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool back(int N, int K, vector<pair<int, int>> nums, int idx, int cursum) {
        if (idx == N) {
            if (cursum == K) {
                return true;
            } else {
                return false;
            }
        }
        return back(N, K, nums, idx+1, cursum + nums[idx].second) || back(N, K, nums, idx+1, cursum + nums[idx].first);
    }

    bool recmemo(int N, int K, vector<pair<int, int>> nums, int idx, int sp, int cursum, vector<vector<int>>& dp) {
        if (idx == N) {
            if (cursum == K) {
                return true;
            } else {
                return false;
            }
        }
        if(dp[idx][sp] != -1) return dp[idx][sp];
        
        dp[idx][sp] = recmemo(N, K, nums, idx+1, !sp, cursum + nums[idx].first, dp) || recmemo(N, K, nums, idx+1, sp, cursum + nums[idx].second, dp);

        return dp[idx][sp];
    }
};

int q1(int N, int K, vector<pair<int, int>> A) {
    Solution s;
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return s.recmemo(N, K, A, 0, 0, 0, dp);
    // return s.back(N, K, A, 0, 0);
}




int main() {
    Solution s;
    // vector<pair<int, int>> nums = {2, 3, 0, 4, 0, 5, 3};
    cout << endl;
    return 0;
}

        // int n = nums.size();
        // for (int i=idx; i<n; i++) {
        //     back(nums, K, idx+1, cursum + nums[i].second);
        // }
        // for (pair<int, int> val: nums) {
        //     sum += val.first;
        // }
        // if (sum == K) {
        //     return true;
        // }

        // int n = nums.size(); 
        // vector<pair<int, int>> copy(nums);
        // for (int i=0; i<n; i++) {
        //     for (int m=0; m<n; m++) {
                
        //     }
        // }

        // return false;