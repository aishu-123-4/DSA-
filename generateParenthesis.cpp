#include <iostream>
#include <vector>

using namespace std;

vector<string> ans;
void para(int n, string sol, int i, int j) {
    if (i == n && j == n) {
        ans.push_back(sol);
        return;
    }
    if (i > n or j > n) {
        return;
    }
    para(n, sol + "(", i+1, j);
    if (j<i) para(n, sol + ")", i, j+1);
}


int main() {
    para(3, "", 0, 0);
    for (auto l: ans) {
        cout << l << " ";
    }
    cout << endl;
    return 0;
}