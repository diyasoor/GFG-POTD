There is a row of N walls in Geeksland. The king of Geeksland ordered Alexa 
to color all the walls on the occasion of New Year. Alexa can color each wall 
with one of the K colors. The cost associated with coloring each wall with a 
particular color is represented by a 2D costs array of size N * K. For example, 
costs[0][0] is the cost of coloring wall 0 with color 0; costs[1][2] is the cost 
of coloring wall 1 with color 2, and so on... Find the minimum cost to color all 
the walls such that no two adjacent walls have the same color.

Note: If you are not able to paint all the walls, then you should return -1.

Example 1:

Input:
N = 4, K = 3
costs[][] = {{1, 5, 7},
             {5, 8, 4},
             {3, 2, 9},
             {1, 2, 4}}

Output:
8
Explanation:
Paint wall 0 with color 0. Cost = 1
Paint wall 1 with color 2. Cost = 4
Paint wall 2 with color 1. Cost = 2
Paint wall 3 with color 0. Cost = 1
Total Cost = 1 + 4 + 2 + 1 = 8
  
Example 2:
Input:
N = 5, K = 1
costs[][] = {{5},
             {4},
             {9},
             {2},
             {1}}
Output:
-1
Explanation:
It is not possible to color all the walls under the given conditions.

Expected Time Complexity: O(N*K)
Expected Space Complexity: O(N*K)

Constraints:

0 <= N <= 10^3
0 <= K <= 10^3
1 <= costs[i][j] <= 10^5

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        int walls=costs.size();
        int color=costs[0].size();
        if(color==1 && walls!=1) return -1;
        
        vector<vector<int>> dp(walls, vector<int>(color));
        for(int i=0;i<color;i++) {
            dp[0][i]=costs[0][i];
        }
        
        int ans=INT_MAX;
        for(int i=1;i<walls;i++) {
            int firstMin = INT_MAX, secondMin = INT_MAX;
            for(int j=0;j<color;j++) {
                if(dp[i-1][j] < firstMin) {
                    secondMin = firstMin;
                    firstMin = dp[i-1][j];
                }
                else if(dp[i-1][j] < secondMin) {
                    secondMin = dp[i-1][j];
                }
            }
            for(int j=0;j<color;j++) {
                if(dp[i-1][j]!=firstMin) {
                    dp[i][j]=costs[i][j]+firstMin;
                }
                else dp[i][j]=costs[i][j]+secondMin;
            }
        }
        return *min_element(dp[walls-1].begin(), dp[walls-1].end());
    }
};
