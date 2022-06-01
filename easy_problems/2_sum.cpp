#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            if(mp.find(nums[i]) != mp.end()) return {mp[nums[i]], i};
            mp[target - nums[i]] = i;
        }
        return {0, 0};
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = s.twoSum(nums, target);
    for (int a: ans) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
