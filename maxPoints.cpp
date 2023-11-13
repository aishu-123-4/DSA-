#include <iostream>
#include <vector>

using namespace std;

void printArray(long long a[], int n) {
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

long long maxPoints(vector<vector<int>> &points)
{
    int m = points.size();
    int n = points[0].size();

    long long preMax[n];
    long long sufMax[n];
    long long dp[n];
    for (int j = 0; j < n; j++)
    {
        dp[j] = points[0][j];
    }
    for (int i = 1; i < m; i++)
    {
        preMax[0] = dp[0];
        for (int j = 1; j < n; j++)
        {
            preMax[j] = max(dp[j], preMax[j - 1] - 1);
        }
        sufMax[n - 1] = dp[n - 1];
        for (int j = n - 2; j >= 0; j--)
        {
            sufMax[j] = max(dp[j], sufMax[j + 1] - 1);
        }
        for (int j = 0; j < n; j++)
        {
            preMax[i] = max(dp[j], sufMax[j + 1] - 1);
        }
        for (int j = 0; j < n; j++)
        {
            dp[j] = points[i][j] + max(preMax[j], sufMax[j]);
        }     
    }
    long long best = dp[0];
    for (int i = 1; i < n; i++)
        best = max(dp[i], best);
    return best;
}

int main()
{
    vector<vector<int>> A = {{1,5},{2,3},{4,2}};
    long long ans = maxPoints(A);
    cout << ans << endl;
}
