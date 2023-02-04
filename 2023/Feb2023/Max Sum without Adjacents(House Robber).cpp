Given an array Arr of size N containing positive integers. Find the maximum sum of a subsequence 
such that no two numbers in the sequence should be adjacent in the array.

Example 1:
Input:
N = 6
Arr[] = {5, 5, 10, 100, 10, 5}
Output: 110
Explanation: If you take indices 0, 3 and 5, then Arr[0]+Arr[3]+Arr[5] = 5+100+5 = 110.
 
Example 2:
Input:
N = 4
Arr[] = {3, 2, 7, 10}
Output: 13
Explanation: 3 and 10 forms a non
continuous  subsequence with maximum
sum.
 
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 10^6
1 ≤ Arri ≤ 10^7

// Method: 1 Recursion
class Solution{
public:	
    int f(int *arr, int n,int i) {
        if(i>=n) return 0;
        // take
        int take=arr[i]+f(arr,n,i+2);
        // not take
        int notTake=f(arr,n,i+1);
        return max(take, notTake);
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    return f(arr, n, 0);
	}
};

// Method: 2 Memoization
class Solution{
public:	
    int f(int *arr, int n,int i, vector<int>& dp) {
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        // take
        int take=arr[i]+f(arr,n,i+2,dp);
        // not take
        int notTake=f(arr,n,i+1,dp);
        return dp[i] = max(take, notTake);
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n+1, -1);
	    return f(arr, n, 0, dp);
	}
};

// Method: 3 Tabulation
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n+2, 0);
	    for(int i=n-1;i>=0;i--) {
	        // take
	        int take=arr[i]+dp[i+2];
	        // not take
	        int notTake=dp[i+1];
	        dp[i]=max(take, notTake);
	    }
	    return dp[0];
	}
};

// Method: 4 Space Optimization
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    int sum1=0, sum2=0, curr;
	    for(int i=0;i<n;i++) {
	        curr=max(arr[i]+sum1, curr);
	        sum1=sum2;
	        sum2=curr;
	    }
	    return curr;
	}
};
