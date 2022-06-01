#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        int sum=0, ssum=0;
        for(int num: nums) {
            if (s.find(num) == s.end()) {
                ssum += num;
                s.insert(num);
            }
            sum += num;
        }
        return (2*ssum - sum);
    }
};

int main() {
    Solution s;
    vector<int> nums = {4, 2, 1, 2, 1};
    int ans = s.singleNumber(nums);
    cout << ans << endl;
    return 0;
}