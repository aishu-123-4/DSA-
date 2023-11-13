#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


    // for(int i=0;i<s.size();i++){
    //     mp[charvalue[s[i]]]++;
    //     if (charvalue[s[i]] == '1')
    //         count++;
    //         maxFreq=max(maxFreq, mp[charvalue[s[i]]]);
        
    //     if(((i-st+1)-maxFreq)>k){
    //         mp[charvalue[s[st]]]--;  
    //         st++;
    //     }
        
    //     maxi=max(maxi,i-st+1);
    // }


int getSpecialSubstring(string s, int k, string charvalue) {
    int st=0;         
    int maxi=0;  
    int count = 0; 
    // int maxFreq=0;    
        // mp[charvalue[s[i]]]++;
    // unordered_map<char,int> mp;
    
    for(int i=0;i<s.size();i++){
        cout << charvalue[s[i] - 'a'] << endl;
        if (charvalue[s[i] - 'a'] == '0')
            count++;

        if (count < k) {
            maxi = max(maxi,i-st+1);
        }
        
        while( (st < i) && count > k) {
            if (charvalue[s[st] - 'a'] == '0') {
                count--;
                st++;
            }
        }
    }
    return maxi;
}

int main()
{
    int ans = getSpecialSubstring("abcde", 1, "10101111111111111111111111");
    cout << ans << endl;
	return 0;
}
