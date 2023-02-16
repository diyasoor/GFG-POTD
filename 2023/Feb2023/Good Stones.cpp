Geek is in a geekland which have a river and some stones in it. Initially geek 
can step on any stone. Each stone has a number on it representing the value of 
exact step geek can move. If the number is +ve then geeks can move right and 
if the number is -ve then geeks can move left. Bad Stones are defined as the 
stones in which if geeks steps, will reach a never ending loop whereas good 
stones are the stones which are safe from never ending loops. Return the 
number of good stones in river.

Example 1:
Input: [2, 3, -1, 2, -2, 4, 1]
Output: 3
Explanation: Index 3, 5 and 6 are safe only. As index 1, 4, 2 forms a cycle and 
from index 0 you can go to index 2 which is part of cycle.

Example 2:
Input: [1, 0, -3, 0, -5, 0]
Output: 2
Explanation: Index 2 and 4 are safe only. As index 0, 1, 3, 5 form cycle.

Expected Time Complexity : O(N), N is the number of stones
Expected Auxiliary Space : O(N), N is the number of stones

Constraints:
   1 <= n < 10^5 (where n is the length of the array)
  -1000 <= arr[i] < 1000
     
class Solution{
public:
    int f(int i, vector<int> &dp, vector<int> &arr, int n) {
        if(i>=n || i<0) return 1;
        if(dp[i]!=-1) return dp[i];
        dp[i]=0;
        return dp[i]=f(i+arr[i], dp, arr, n);
    }
    int goodStones(int n,vector<int> &arr){
        // Code here
        vector<int> dp(n, -1);
        for(int i=0;i<n;i++) {
            if(dp[i]==-1) f(i, dp, arr, n);
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            if(dp[i]==1) ans++;
        }
        return ans;
    }  
};
