#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int L = 0, R = n-1;
        
        while (L <= R) {
            int mid = L + (R - L)/2;
            if (target == nums[mid]) return mid;
            
            if (nums[L] <= nums[mid]) {
                if (target >= nums[L] and target < nums[mid]) R = mid - 1;
                else L = mid + 1;
            } else {
                if (target > nums[mid] and target <= nums[R]) L = mid + 1;
                else R = mid - 1;
            }           
        }
        return -1;
    }
};


int main() {
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int ans = s.search(nums, target);
    cout << ans << endl;
    return 0;
}