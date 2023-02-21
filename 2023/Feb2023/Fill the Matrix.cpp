Given a matrix with dimensions N x M, entirely filled with zeroes except for one 
position at co-ordinates X and Y containing '1'. Find the minimum number of 
iterations in which the whole matrix can be filled with ones.
Note: In one iteration, '1' can be filled in the 4 neighbouring elements of 
a cell containing '1'.

Example 1:
Input:
N = 2, M = 3
X = 2, Y = 3
Output: 3 
Explanation: 3 is the minimum possible 
number of iterations in which the
matrix can be filled.

Example 2:
Input:
N = 1, M = 1
X = 1, Y = 1 
Output: 0
Explanation: The whole matrix is 
already filled with ones.

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(1)
  
Constraints:
1 ≤ N, M ≤ 10^3
1 ≤ X ≤ N
1 ≤ Y ≤ M 

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // code here
        vector<vector<int>> mat(N+1, vector<int>(M+1));
        mat[x][y]=1;
        
        queue<pair<int,int>> q;
        q.push({x,y});
        
        int iteration=0;
        while(!q.empty()) {
            int size=q.size();
            while(size-- > 0) {
                auto temp=q.front();
                q.pop();
                
                int i=temp.first;
                int j=temp.second;
                
                // up
                if(i>1 && mat[i-1][j]==0) {
                    q.push({i-1,j});
                    mat[i-1][j]=1;
                }
                // right
                if(j<M && mat[i][j+1]==0) {
                    q.push({i,j+1});
                    mat[i][j+1]=1;
                }
                // down
                if(i<N && mat[i+1][j]==0) {
                    q.push({i+1,j});
                    mat[i+1][j]=1;
                }
                // left
                if(j>1 && mat[i][j-1]==0) {
                    q.push({i,j-1});
                    mat[i][j-1]=1;
                }
            }
            if(!q.empty()) iteration++;
        }
        return iteration;
    }
};
