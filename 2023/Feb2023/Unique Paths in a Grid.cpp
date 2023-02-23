You are given a matrix grid of n x  m size consisting of values 0 and 1. A value 
of 1 means that you can enter that cell and 0 implies that entry to that cell is not allowed.

You start at the upper-left corner of the grid (1, 1) and you have to reach the 
bottom-right corner (n, m) such that you can only move in the right or down direction from every cell.

Your task is to calculate the total number of ways of reaching the target modulo (109+7).
Note: The first (1, 1) and last cell (n, m) of the grid can also be 0


Example 1:
Input:
n = 3, m = 3
grid[][] = {{1, 1, 1};
            {1, 0, 1};
            {1, 1, 1}}
Output:
2
Explanation:
1 1 1
1 0 1
1 1 1
This is one possible path.
1 1 1
1 0 1
1 1 1
This is another possible path.
  
Example 2:
Input:
n = 1, m = 3
grid = {{1, 0, 1}}
Output :
0
Explanation:
There is no possible path to reach the end.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n,m ≤ 10^3

class Solution {
  public:
    int MOD=1e9+7;
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=0;i<n;i++) {
            if(grid[i][0]==0) break;
            dp[i][0]=1;
        }
        for(int i=0;i<m;i++) {
            if(grid[0][i]==0) break;
            dp[0][i]=1;
        }
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if(grid[i][j]==0) dp[i][j]=0;
                else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
        return dp[n-1][m-1];
    }
};
