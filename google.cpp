#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool question(vector<pair<int, int>> nums, int K) {
        int sum = 0;
        for (pair<int, int> val: nums) {
            sum += val.first;
        }
        if (sum == K) {
            return true;
        }

        int n = nums.size(); 
        vector<pair<int, int>> copy(nums);
        for (int i=0; i<n; i++) {
            for (int m=0; m<n; m++) {
                
            }
        }

        return false;
    }

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
};

class Solution {
public:
    int maxsum = 0;
    void question(int N, int K, vector<long long> A, vector<int> already, int idx, int cursum) {
        if (idx == N) {
            maxsum = max(maxsum, cursum);
            return;
        }
    
        for (int j = 1; j<K; j++) {
            if (already[j - 1] <= 2) {
                already[j-1]++;
                int ans = A[idx]&j;
                question( N, K, A, already,idx+1, cursum + ans);
                already[j-1]--;
            }
        }
    }
};

int maxSum(int N, int K, vector<long long> A) {
    Solution s;
    int n = A.size();
    vector<int> already(n, 0);
    s.question(N, K, A, already, 0, 0);
    return s.maxsum; 
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