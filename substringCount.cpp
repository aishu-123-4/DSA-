#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int substrings(string s, int l, int r) {
   int count = 0;
    for (int i = l; i <= r; i++) {
        string subStr;
        for (int j = i; j <= r; j++) {
            subStr += s[j];
            if (subStr.front() == subStr.back()) {
               count++;
            }
        }
    }
   return count;
}

vector<int> all(string s) {
   int n = s.length(); 
   vector<int> dp(n, 0);
      // int count = 0;
    for (int i = 0; i < n; i++) {
        string subStr;
        for (int j = i; j < n; j++) {
            subStr += s[j];
            if (subStr.front() == subStr.back()) {
               dp[j]++;
            }
        }
    }
   return dp;
}

vector<int> all1(string s) {
   int n = s.length(); 
   vector<int> dp(n, 0);
      // int count = 0;
    for (int i = 0; i < n; i++) {
        string subStr;
        for (int j = i; j>=0; j--) {
            subStr = (s[j] + subStr);
            if (subStr.front() == subStr.back()) {
               dp[i]++;
            }
        }
    }
   return dp;
}


vector<int> substrings1(int n, int q, string s, vector<vector<int>> queries) {
   vector<int> dp = all1(s);
   vector<int> prefix_dp(s.length() + 1, 0);
   for (int i=1; i< dp.size(); i++) {
      prefix_dp[i] = prefix_dp[i-1] + i;
   }
   for (auto i: dp) {
      cout << i << endl;
   }
   vector<int> ans;
   for (auto que: queries) {  
      int val = prefix_dp[que[1]-1] - prefix_dp[que[0]-1];
      ans.push_back(val);
   }
   return ans;
}


vector<int> sub_string_sol(int n, int q, string s, vector<vector<int>> queries) {
   vector<int> ans;
   for (auto que: queries) {
      int val = substrings(s, que[0]-1, que[1]-1); 
      ans.push_back(val);  
   }
   return ans;
}


int main()
{
   vector<vector<int>> queries = {{3, 6}, {1,6}};
    // vector<int> ans = sub_string_sol(5, 1, "abcaab", queries);
   vector<int> ans = substrings1(5, 1, "abcaab", queries);
   // for (auto i: ans) {
   //    cout << i << endl;
   // }
   return 0;
}