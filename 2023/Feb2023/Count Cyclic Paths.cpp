Given a triangular pyramid with its vertices marked as O, A, B and C and a 
number N, the task is to find the number of ways such that a person starting 
from the origin O initially, reaches back to the origin in N steps. In a 
single step, a person can go to any of its adjacent vertices.

Example 1:
Input:
N = 1
Output: 0
Explanation: The minimum length of
a cyclic path is 2.
  
Example 2:
Input:
N = 2
Output: 3
Explanation: The three paths are :
O-A-O, O-B-O, O-C-O

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ N ≤ 10^6

// RECURSION
class Solution{   
public:
    int MOD=1e9+7;
    int f(int n, char position) {
        if(n==0 && position=='O') return 1;
        if(n==0 && position!='O') return 0;
        
        int ans=0;
        if(position=='O') {
            ans += f(n-1, 'A') % MOD;
            ans += f(n-1, 'B') % MOD;
            ans += f(n-1, 'C') % MOD;
        }
        if(position=='A') {
            ans += f(n-1, 'O') % MOD;
            ans += f(n-1, 'B') % MOD;
            ans += f(n-1, 'C') % MOD;
        }
        if(position=='B') {
            ans += f(n-1, 'A') % MOD;
            ans += f(n-1, 'O') % MOD;
            ans += f(n-1, 'C') % MOD;
        }
        if(position=='C') {
            ans += f(n-1, 'A') % MOD;
            ans += f(n-1, 'B') % MOD;
            ans += f(n-1, 'O') % MOD;
        }
        
        return ans;
    }
    int countPaths(int N){
        // code here 
        return f(N, 'O');
    }
};

// MEMOIZATION
class Solution{   
public:
    int MOD=1e9+7;
    int f(int n, char position, vector<vector<int>>& dp) {
        if(n==0 && position=='O') return 1;
        if(n==0 && position!='O') return 0;
        
        int ans=0;
        if(position=='O') {
            if(dp[0][n]!=-1) return dp[0][n];
            ans = (ans + f(n-1, 'A', dp)) % MOD;
            ans = (ans + f(n-1, 'B', dp)) % MOD;
            ans = (ans + f(n-1, 'C', dp)) % MOD;
            return dp[0][n]=ans;
        }
        if(position=='A') {
            if(dp[1][n]!=-1) return dp[1][n];
            ans = (ans + f(n-1, 'O', dp)) % MOD;
            ans = (ans + f(n-1, 'B', dp)) % MOD;
            ans = (ans + f(n-1, 'C', dp)) % MOD;
            return dp[1][n]=ans;
        }
        if(position=='B') {
            if(dp[2][n]!=-1) return dp[2][n];
            ans = (ans + f(n-1, 'A', dp)) % MOD;
            ans = (ans + f(n-1, 'O', dp)) % MOD;
            ans = (ans + f(n-1, 'C', dp)) % MOD;
            return dp[2][n]=ans;
        }
        if(position=='C') {
            if(dp[3][n]!=-1) return dp[3][n];
            ans = (ans + f(n-1, 'A', dp)) % MOD;
            ans = (ans + f(n-1, 'B', dp)) % MOD;
            ans = (ans + f(n-1, 'O', dp)) % MOD;
            return dp[3][n]=ans;
        }
        
        return ans;
    }
    int countPaths(int N){
        // code here 
        vector<vector<int>> dp(4, vector<int>(N+1, -1));
        return f(N, 'O', dp);
    }
};

// TABULATION
class Solution{   
public:
    int countPaths(int N){
        // code here 
        int MOD=1e9+7;
        vector<vector<int>> dp(4, vector<int>(N+1));
        dp[0][0]=1;
        for(int j=1;j<=N;j++) {
            for(int i=0;i<4;i++) {
                dp[i][j] = (dp[i][j] + dp[(i+1)%4][j-1]) % MOD;
                dp[i][j] = (dp[i][j] + dp[(i+2)%4][j-1]) % MOD;
                dp[i][j] = (dp[i][j] + dp[(i+3)%4][j-1]) % MOD;
            }
        }
        return dp[0][N];
    }
};
