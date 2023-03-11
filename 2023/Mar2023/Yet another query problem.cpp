You are given an array of N elements and num queries, In each query you are given three 
numbers L,R and K and you have to tell, how many indexes are there in between L and R
(L<=i<=R) such that the frequency of a[i] from index i to n-1 is k.

Note: 0-based indexing

Example 1:

Input:
N=5
num=3
A={1,1,3,4,3}
Q={{0,2,2},{0,2,1},{0,4,2}}
Output:
2 1 2
Explanation:
For query 1: 0 2 2
L=0,R=2,K=2
let, L<=i<=R
For i=0: frequency of a[i] i.e. 1 from i to n-1 is 2.
For i=1: frequency of a[i] i.e. 1 from i to n-1 is 1.
For i=2: frequency of a[i] i.e. 3 from i to n-1 is 2.
Hence we have two elements from index 0 to 2 
whose frequency from i to n-1 is 2.

For query 2: 0 2 1
L=0,R=2,K=1
As we can see from the above query that there is 
only a single element in 0 to 2 whose frequency 
from i to n-1 is 1.

For query 3: 0 4 2
The answer will be 2 because of the index 0 and 2.
Example 2:

Input:
N=5
num=2
A={1,1,1,1,1}
Q={{0,4,2},{0,4,1}}
Output:
1 1 
Explanation: 
For query 1: 0 4 4 
L=0,R=4,K=4 
let, L<=i<=R 
For i=0: frequency of a[i] i.e. 1 from i to n-1 is 5. 
For i=1: frequency of a[i] i.e. 1 from i to n-1 is 4. 
For i=2: frequency of a[i] i.e. 1 from i to n-1 is 3.
For i=3: frequency of a[i] i.e. 1 from i to n-1 is 2.
For i=4: frequency of a[i] i.e. 1 from i to n-1 is 1. 
Hence we have one elements from index 0 to 4 whose frequency from i to n-1 is 2. 

Similarly For query 2: 
there is only 1 element in 0 to 4 whose frequency from i to n-1 is 1.
Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N2) 

Constraints:
1 <= N <= 103
0 <= Q < 103
1 <= A[i] <= 105
  
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        // code here
        int freq[N];
        for(int i=0;i<N;i++) {
            int cnt=1;
            for(int j=i+1;j<N;j++) {
                if(A[i]==A[j]) cnt++;
            }
            freq[i]=cnt;
        }
        vector<int> ans;
        for(int i=0;i<num;i++) {
            int L=Q[i][0];
            int R=Q[i][1];
            int K=Q[i][2];
            int cnt=0;
            for(int j=L;j<=R;j++) {
                if(freq[j]==K) cnt++; 
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

