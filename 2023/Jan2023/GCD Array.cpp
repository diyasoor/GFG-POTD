You are given an array, arr of length N, and also a single integer K . Your task is to 
split the array arr into K non-overlapping, non-empty subarrays. For each of the 
subarrays, you calculate the sum of the elements in it. Let us denote these sums as 
S1, S2, S3, ..., SK. Where Si denotes the sum of the elements in the ith subarray 
from left.

Let G = GCD( S1, S2 ,S3 , ..., SK).

Find the maximum value of G that can be obtained. 
The array may contain duplicate elements.

Example 1:
Input:
N = 5
K = 4
arr[] = {6, 7, 5, 27, 3}
Output: 3
  
Explanation: 
Since K = 4, you have to split the array into 4 subarrays.
For optimal splitting, split the array into
4 subarrays as follows: [[6], [7, 5], [27], [3]]
Therefore, S1 = 6, S2 = 7 + 5 = 12, S3 = 27, S4 = 3
Hence, G = GCD(S1, S2, S3, S4) = GCD(6, 12, 27, 3) = 3
It can be shown that 3 is the maximum value of G that can be obtained.
Thus, the answer is 3.
  
Expected Time Complexity: O(N * x)
Expected Auxiliary Space: O(x), x is the number of factors of the sum of all elements.

Constraints:
1 <= N <= 104
1 <= K <= N
1 <= arr[i] <= 105
  
class Solution {
  public:
    int solve(int N, int K, vector<int> &arr) {
        // code here
        int totalSum=accumulate(arr.begin(), arr.end(), 0);
        
        vector<int> divisors;
        int M=sqrt(totalSum);
        for(int i=1;i<=M;i++) {
            if(totalSum%i==0) {
                divisors.push_back(i);
                divisors.push_back(totalSum/i);
            }
        }
        // calculate the prefix sum
        vector<int> prefixSum(arr.begin(), arr.end());
        for(int i=1;i<N;i++) {
            prefixSum[i]+=prefixSum[i-1];
        }
        int maxGCD=1;
        for(int n: divisors) {
            int cntK=0;
            for(int i=0;i<N;i++) {
                if(prefixSum[i]%n==0) 
                    cntK++;
            }
            if(cntK>=K) maxGCD=max(maxGCD, n);
        }
        return maxGCD;
    }
};
