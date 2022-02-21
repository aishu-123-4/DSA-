#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int> house) {
    int n = house.size();
    int dp[n];
    dp[0] = house[0];
    dp[1] = max(dp[0], house[1]);

    for (int i=2; i<n; i++) {
        dp[i] = max(dp[i-1], house[i] + dp[i-2]);
    }
    return dp[n-1];
}


int main() {
    vector<int> house = {2,7,9,3,1};
    int res = rob(house);
    cout << res << endl;
    return 0;
}