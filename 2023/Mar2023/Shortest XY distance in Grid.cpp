Give a N*M grid of characters 'O', 'X', and 'Y'. Find the minimum Manhattan 
distance between a X and a Y.

Manhattan Distance :
| row_index_x - row_index_y | + | column_index_x - column_index_y |

Example 1:
Input:
N = 4, M = 4
grid  = {{X, O, O, O}
         {O, Y, O, Y}
         {X, X, O, O}
         {O, Y, O, O}}
Output: 1
Explanation:
{{X, O, O, O}
{O, Y, O, Y}
{X, X, O, O}
{O, Y, O, O}}
The shortest X-Y distance in the grid is 1.
One possible such X and Y are marked in bold
in the above grid.
  
Example 2:
Input:
N = 3, M = 3
grid = {{X, X, O}
        {O, O, Y}
        {Y, O, O}}
Output : 2
Explanation:
{{X, X, O}
 {O, O, Y}
 {Y, O, O}}
The shortest X-Y distance in the grid is 2.
One possible such X and Y are marked in bold
in the above grid.

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(N*M)


Constraints:
1 ≤ N, M ≤ 10^3  

There exists at least one 'X' and at least one 'Y' in the grid.

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        // code here
        vector<vector<int>> visited(N, vector<int>(M));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(grid[i][j]=='X') {
                    q.push({{i,j}, 0});
                    visited[i][j]=1;
                }
            }
        }
        int ans=INT_MAX;
        while(!q.empty()) {
            int size=q.size();
            
            for(int i=0;i<size;i++) {
                auto temp=q.front();
                q.pop();
                
                auto p=temp.first;
                int len=temp.second;
                
                int x=p.first, y=p.second;
                
                if(grid[x][y]=='Y') return len;
                
                if(x-1>=0 and !visited[x-1][y]){
                    q.push({{x-1,y},len+1});
                    visited[x-1][y]=true;
                }
                if(y-1>=0 and !visited[x][y-1]){
                    q.push({{x,y-1},len+1});
                    visited[x][y-1]=true;
                }
                if(x<=N-2 and !visited[x+1][y]){
                    q.push({{x+1,y},len+1});
                    visited[x+1][y]=true;
                }
                if(y<=M-2 and !visited[x][y+1]){
                    q.push({{x,y+1},len+1});
                    visited[x][y+1]=true;
                }
            }
        }
        return ans;
        
    }
};
