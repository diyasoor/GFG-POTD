You are given an array of n elements, initially all a[i] = 0. Q queries need to be 
performed. Each query contains three integers l, r, and x  and you need to change 
all a[i] to (a[i] | x) for all l ≤ i ≤ r.

Return the array after executing Q queries.

Example 1:
Input:
N=3, Q=2
U=[[1, 3, 1],
   [1, 3, 2]]

Output:
a[]={3,3,3}
Explanation: 
Initially, all elements of the array are 0. After execution of the
first query, all elements become 1 and after execution of the 
second query all elements become 3.

Example 2:
Input:
N=3, Q=2
U=[[1, 2, 1],
   [3, 3, 2]]
Output:
a[]={1,1,2}
Explanantion:
[0,0,0] => [1,1,0] => [1,1,2]
 
Expected Time Complexity: O(N)
Expected Space Complexity: O(N)

Constraints:
1<=N<=10^5
1<=Q<=10^5
1<=U[i][0] <= U[i][1]<=N
1<= U[i][2] <=10^5

class Solution{
    public:
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            // code here
            vector<vector<int>> temp(32, vector<int>(N+1));
            for(int i=0;i<Q;i++) {
                int l=U[i][0], r=U[i][1], x=U[i][2];
                l--;r--;
                for(int j=0;j<32;j++) {
                    if(x&(1<<j)) {
                        temp[j][l]++;
                        temp[j][r+1]--;
                    }
                }
            }
            for(int j=0;j<32;j++) {
                for(int i=1;i<N;i++) {
                    temp[j][i]+=temp[j][i-1];
                }
            }
            vector<int> ans(N);
            for(int j=0;j<32;j++) {
                for(int i=0;i<N;i++) {
                    if(temp[j][i]!=0) {
                        ans[i]|=(1<<j);
                    }
                }
            }
            return ans;
        }
};
