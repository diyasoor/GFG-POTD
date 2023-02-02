Given a binary matrix of dimensions N * M. One can perform the given operation into the matrix.

If the value of matrix[i][j] is 0, then traverse in the same direction and check the next value.
If the value of matrix[i][j] is 1, then update matrix[i][j] to 0 and change the current direction 
from up, right, down, or left to the directions right, down, left, and up respectively.
Initially you start from cell(0, 0), moving in right direction.

The task is to find the indices of the matrix  which leads to outside the matrix from the traversal 
of the given matrix from the cell (0, 0) by performing the operations.
  
Example 1:
Input:
matrix[][] = {{0,1},
              {1,0}}
Output: (1,1)

Example 2:
Input: 
matrix[][] = {{0, 1, 1, 1, 0},
                   {1, 0, 1, 0, 1},
              {1, 1, 1, 0, 0}}

Output: (2,0)
Explanation: We will leave the grid after visiting the index (2,0).
 
Expected Time Complexity: O(N)
Expected Space Complexity: O(1)

Constrains:
1<= N, M <=1000
0<= matrix[i][j] <=1
  
class Solution{
    public:
    bool isSafe(int m, int n, int i, int j) {
        if(i<0 || j<0 || i>=m || j>=n) return false;
        return true;
    }
    pair<int,int> endPoints(vector<vector<int>> mat){
        //code here
        int m=mat.size(), n=mat[0].size();
        map<char, char> directions = {{'u', 'r'}, {'r', 'd'}, {'d', 'l'}, {'l', 'u'}};
        
        char currDir = 'r';
        int i=0,j=0;
        int curr_i=0, curr_j=0;
        while(isSafe(m, n, i, j)) {
            curr_i=i, curr_j=j;
            
            if(mat[i][j]==1) {
                char newDir = directions[currDir];
                mat[i][j]=0;
                
                if(newDir=='u') i--;
                else if(newDir=='d') i++;
                else if(newDir=='r') j++;
                else if(newDir=='l') j--;
                
                currDir = newDir;
            }
            else {
                if(currDir=='u') i--;
                else if(currDir=='d') i++;
                else if(currDir=='r') j++;
                else if(currDir=='l') j--;
            }
        }
        return {curr_i, curr_j};
    }

};

 
