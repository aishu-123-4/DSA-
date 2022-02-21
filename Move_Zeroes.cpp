#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void swap(int* a, int* b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }

    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
		int j = 0;
		while(j < n)
		{
			if(nums[j] != 0)  {
                swap(&nums[count++], &nums[j]);
            }
            j++;
		}
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 0, 4, 0, 5, 3};
    s.moveZeroes(nums);
    for (int a: nums) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}