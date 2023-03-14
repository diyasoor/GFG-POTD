We have been given N balloons, each with a number of coins associated with it. 
On bursting a balloon i, the number of coins gained is equal to A[i-1]*A[i]*A[i+1].
Also, balloons i-1 and i+1 now become adjacent. Find the maximum possible profit 
earned after bursting all the balloons. Assume an extra 1 at each boundary.

Example 1:
Input: 
N=2
a[]={5, 10}
Output: 60
Explanation: First Burst 5, Coins = 1*5*10
              Then burst 10, Coins+= 1*10*1
              Total = 60
Example 2:
Input:
N=4
a[] = {3,1,5,8}
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167.

Expected Time Complexity: O(N^3)
Expected Space Complexity: O(N^2)

Constraints:
1 <= N <= 400
0 <= a[i] <= 100

class Solution{
    public:
        int f(vector<int>& a, int l, int r, vector<vector<int>>& dp) {
            if(l-r==1) return 0;
            
            if(dp[l][r]!=-1) return dp[l][r];
            
            int ans=0;
            for(int m=l+1; m<r; m++) {
                int coins=a[l]*a[m]*a[r] + f(a, l, m, dp) + f(a, m, r, dp);
                ans = max(ans, coins);
            }
            return dp[l][r]=ans;
        }
        int maxCoins(int N, vector <int> &a)
        {
                // write your code here
                vector<int> arr(N+2);
                int n=N+2;
                arr[0]=1, arr[n-1]=1;
                
                for(int i=1;i<=n-2;i++) arr[i]=a[i-1];
                
                vector<vector<int>> dp(n,vector<int>(n, -1));
                
                return f(arr, 0, n-1, dp);
        }
};
