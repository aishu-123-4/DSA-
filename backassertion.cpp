#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ans = -1;
void backtracking(vector<vector<int>> assertions, int idx, int val, int l, int r) {
        if (idx >= assertions.size()) {
            ans = max(ans, val);
            return;
        }
		if (assertions[idx][0] == 1) {
			if ((l <= assertions[idx][1] && assertions[idx][2] <= r)) {
				backtracking(assertions, idx+1, val+1, max(l,assertions[idx][1]), min(r,assertions[idx][1]));
			}
		} else {
			if (assertions[idx][1] > l) {
				backtracking(assertions, idx+1, val+1, min(l,assertions[idx][1]), r);
			}
			else if (r < assertions[idx][2]) {
				backtracking(assertions, idx+1, val+1, l, max(r, assertions[idx][2]));
			}
		}    
		backtracking(assertions, idx+1, val, l, r);

}

int solve(int q, vector<vector<int>> assertions) {
	backtracking(assertions, 0, 0, INT_MIN, INT_MAX);
	return q - ans;
}



int main()
{
	vector<vector<int>> assertions = {{2, 2, 2}, {1, 1, 2}, {1, 9, 9}, {1, 4, 6}};
	int ans = solve(4, assertions);
	cout << ans << endl;
}
