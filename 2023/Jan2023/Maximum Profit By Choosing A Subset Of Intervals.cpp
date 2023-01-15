Given a list intervals of n intervals, the ith element [s, e, p] denotes the starting point s, 
ending point e, and the profit p earned by choosing the ith interval. Find the maximum profit 
one can achieve by choosing a subset of non-overlapping intervals.

Two intervals [s1, e1, p1] and [s2, e2, p2] are said to be non-overlapping if [e1 <= s2] and [s1 < s2].

Example 1:
Input:
n = 3
intervals = {
{1, 2, 4},
{1, 5, 7},
{2, 4, 4}
}
Output:
8
Explanation:
One can choose intervals [1, 2, 4] and [2, 4, 4] for a 
profit of 8.
  
Constraints:

1 <= n and n <= 10^4 (either O(N) or O(NlogN))
1 <= starting point of ith interval < ending point of ith interval <= 105
1 <= profit earned by choosing ith interval <= 105
  
class Solution {
  public:
    int searchNonOverlappingPlace(vector<vector<int>> &arr, int endTime) {
        int lo=0,hi=arr.size()-1, idx=arr.size();
        while(lo<=hi) {
            int mid=lo+(hi-lo)/2;
            if(arr[mid][0] < endTime) lo=mid+1;
            else {
                hi=mid-1;
                idx = min(idx, mid);
            }
        }
        return idx;
    }
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        // Write your code here.
        sort(intervals.begin(), intervals.end());
        vector<int> dp(n,0);
        for(int i=n-1;i>=0;i--) {
            int idx = searchNonOverlappingPlace(intervals, intervals[i][1]);
            if(idx>=n) dp[i] = intervals[i][2];
            else dp[i] = intervals[i][2] + dp[idx];
            if(i!=n-1) dp[i] = max(dp[i], dp[i+1]);
        }
        return dp[0];
    }
};
