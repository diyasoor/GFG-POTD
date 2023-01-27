A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
You are an FBI agent. You have to determine the total number of ways that message can be 
decoded, as the answer can be large return the answer modulo 109 + 7.
Note: An empty digit sequence is considered to have one decoding. It may be assumed that 
the input contains valid digits from 0 to 9 and If there are leading 0s, extra trailing 
0s and two or more consecutive 0s then it is an invalid string.

Example 1:
Input: str = "123"
Output: 3
Explanation: "123" can be decoded as "ABC"(123),
"LC"(12 3) and "AW"(1 23).

  
Expected Time Complexity: O(n)
Expected Space Complexity: O(n) where n  = |str|

Constraints:
1 <= |str| <= 10^4

class Solution {
	public:
	    int MOD = 1e9+7;
	    int fun(string s, int i, vector<int>& dp) {
	        if(i<=0) return 1;
	        
	        if(dp[i]!=-1) return dp[i];
	        int cnt=0;
	        if(s[i]>='1') cnt=fun(s, i-1, dp);
	        if((s[i-1]=='1' && s[i]<='9') || (s[i-1]=='2' && s[i]<'7'))
	            cnt += fun(s, i-2, dp);
	        return dp[i] = cnt % MOD;
	    }
		int CountWays(string str){
		    // Code here
		    if(str.size()==1 && str[0]!='0') return 1;
		    vector<int> dp(str.size(), -1);
		    return fun(str, str.size()-1, dp) % MOD;
		}

};
