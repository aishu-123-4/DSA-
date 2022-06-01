#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int> &nums, int k) {
    int n = nums.size();
    k %= n;
    int newarr[n];
    for (int i = 0; i < n; i++) {
        newarr[(i + k) % n] = nums[i];
    }
    for (int i = 0; i < n; i++) {
        nums[i] = newarr[i];
    }
}

int main() {
    vector<int> nums = {2, 3, 0, 4, 0, 5, 3};
    int k = 3;
    rotate(nums, k);
    for (int a : nums) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}