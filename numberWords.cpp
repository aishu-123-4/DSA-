#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> ans;
    
    void rec(string s, int start, string sol) {
        if (start == s.length()) {
            ans.push_back(sol);
            return;
        }
        if (start > s.length()) {
            return;
        }

        for (int i=1; i<3; i++) {
            string tmp = s.substr(start, i);
            int val = atoi(tmp.c_str());
            if (val > 25 or (tmp.size() > 1 and tmp[0] == '0')) continue;

            rec(s, start+i, sol + (char)(val + 65));
        }

    }
    


    vector<string> numWords(string s) {
        rec(s, 0, "");
        return ans;
    }
};

int main() {
    Solution s;
    string nums = "22019417";
    vector<string> ans  = s.numWords(nums);
    for (auto st: ans) {
        cout << st << " ";
    }
    cout << endl;
    return 0;
}




    // unordered_map<int, char> mp;

    // Solution() {
    //     mp[0] = 'A', mp[1] = 'B';
    //     mp[2] = 'C', mp[3] = 'D';
    //     mp[4] = 'E', mp[5] = 'F';
    //     mp[6] = 'G', mp[7] = 'H';
    //     mp[8] = 'I', mp[9] = 'J';
    //     mp[10] = 'K', mp[11] = 'L';
    //     mp[12] = 'M', mp[13] = 'N';
    //     mp[14] = 'O', mp[15] = 'P';
    //     mp[16] = 'Q', mp[17] = 'R';
    //     mp[18] = 'S', mp[19] = 'T';
    //     mp[20] = 'U', mp[21] = 'V';
    //     mp[22] = 'W', mp[23] = 'X';
    //     mp[24] = 'Y', mp[25] = 'Z';
    // }