Given a binary string S consists only of 0s and 1s. The task is to calculate the 
number of substrings that have more 1s than 0s.

Example 1:

Input:
S = "011"
Output: 4
Explanation: There are 4 substring which 
has more 1s than 0s. i.e "011","1","11" and "1"
Example 2:

Input:
S = "0000"
Output: 0
Explanation: There is no substring
which has more 1s than 0s
Your Task:  
You dont need to read input or print anything. Complete the function countSubstring() 
which takes the string S as input parameter and returns the number of substring 
which has more 1s than 0s.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)

Constraints:
1 < |S| < 105
|S| denotes the length of the string S

class Solution{
public:
  long long countSubstring(string S){
    // code here
    int n=S.size();
    vector<long> dp(2*n + 1);
    int cnt=n, minus=0;
    // initializing the dp array when the 
    // substrings are starting from index 0
    for(int i=0;i<n;i++) {
        if(S[i]=='0') cnt--;
        else cnt++;
        
        if(cnt<=n) minus++;
        dp[cnt]++;
    }
    
    long ans =0;
    int idx=n;
    for(int i=0;i<n;i++) {
        ans += (n-i-minus)*1l;
        if(S[i]=='1') {
            idx++;
            dp[idx]--;
            minus+= dp[idx];
        }
        else {
            minus--;
            minus-=dp[idx];
            idx--;
            dp[idx]--;
        }
    }
    return ans;
  }
};
