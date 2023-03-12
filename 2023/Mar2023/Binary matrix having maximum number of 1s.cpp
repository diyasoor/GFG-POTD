Given a binary matrix (containing only 0 and 1) of order NxN. All rows are 
sorted already, We need to find the row number with the maximum number of 
1s. Also, find the number of 1s in that row.
Note:
1. In case of a tie, print the smaller row number.
2. Row number should start from 0th index.

Example 1
Input:
N=3
mat[3][3] = {0, 0, 1, 
              0, 1, 1, 
              0, 0, 0}
Output:
Row number = 1
MaxCount = 2
Explanation:
Here, max number of 1s is in row number 1
and its count is 2.

Example 2
Input:
N=3
mat[3][3] = {1, 1, 1, 
              1, 1, 1, 
              0, 0, 0}
Output:
Row number = 0
MaxCount = 3

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 10^3
0 <= mat[][]<= 1
  
// T.C:O(N)
class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
        int cntOne=0,row=0, j=N-1;
        for(int i=0;i<N;i++) {
            while(j>=0 && mat[i][j]==1) {
                j--;
                cntOne++;
                row=i;
            }
        }
        return {row, cntOne};
    }
};
