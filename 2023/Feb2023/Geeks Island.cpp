Geeks Island is represented by an N * M matrix mat. The island is touched by the Indian 
Ocean from the top and left edges and the Arabian Sea from the right and bottom edges. 
  Each element of the matrix represents the height of the cell.

Due to the rainy season, the island receives a lot of rainfall, and the water can flow 
in four directions(up, down, left, or right) from one cell to another one with height 
equal or lower.

You need to find the number of cells from where water can flow to both the Indian Ocean 
and the Arabian Sea.

Example 1:
Input:
N = 5, M = 5
mat[][] =    {{1, 3, 3, 2, 4},
               {4, 5, 6, 4, 4},
               {2, 4, 5, 3, 1},
               {6, 7, 1, 4, 5},
               {6, 1, 1, 3, 4}}
Output: 8
Explanation:
Indian    ~   ~   ~   ~   ~
Ocean  ~  1   3   3   2  (4) *
        ~  4   5  (6) (4) (4) *
        ~  2   4  (5)  3   1  *
        ~ (6) (7)  1   4   5  *
        ~ (6)  1   1   3   4  *           
           *   *   *   *   * Arabian Sea
Water can flow to both ocean and sea from the cells
denoted by parantheses().For example at index(1,2), the height of that island is 6. If a water drop falls on that island, water can flow to up direction(as 3<=6) and reach to Indian Ocean. ALso, water can flow to right direction(as 6>=4>=4) and reach to Arabian Sea.

Example 2:
Input:
N = 2, M = 3
mat[][] =    {{1, 1, 1},
               {1, 1, 1}}
Output: 6 
Explanation:
Water can flow from all cells to both Indian Ocean and Arabian Sea as the height of all islands are same.

Expected Time Complexity : O(N*M)
Expected Auxiliary Space : O(N*M)

Constraints:

1 <= N, M <= 10^3
1 <= mat[i][j] <= 10^6

class Solution{   
public:
    vector<vector<int>> dir{{1,0}, {-1,0}, {0,1}, {0,-1}};
    void dfs(vector<vector<int>>&mat, vector<vector<int>>&dp, int i,int j) {
        dp[i][j]=1;
        for(auto d: dir) {
            int x=i+d[0];
            int y=j+d[1];
            if(x<0 || y<0 || x>=mat.size() || y>=mat[0].size() || mat[x][y] < mat[i][j] || dp[x][y]==1)
                continue;
            dfs(mat,dp,x,y);
        }
    }
    int water_flow(vector<vector<int>> &mat,int N,int M){
    // Write your code here.
        vector<vector<int>> dp1(N, vector<int>(M,0));
        vector<vector<int>> dp2(N, vector<int>(M,0));
        
        for(int i=0;i<N;i++) {
            dfs(mat, dp1, i, 0);
            dfs(mat, dp2, i, M-1);
        }
        
        for(int i=0;i<M;i++) {
            dfs(mat, dp1, 0, i);
            dfs(mat, dp2, N-1, i);
        }
        
        int ans=0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(dp1[i][j]==1 && dp2[i][j]==1) ans++;
            }
        }
        
        return ans;
    }
};
