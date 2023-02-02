Given a maze with N cells. Each cell may have multiple entry points but not more than one 
exit(i.e entry/exit points are unidirectional doors like valves).
You are given an array Edge[] of N integers, where Edge[i] contains the cell number that 
can be reached from of cell i in one step. Edge[i] is -1 if the ith cell doesn't have an exit. 
The task is to find the largest sum of a cycle in the maze(Sum of a cycle is the sum of 
the cell indexes of all cells present in that cycle).

Note:The cells are named with an integer value from 0 to N-1. If there is no cycle in the
graph then return -1.

Example 1:
Input:
N = 4
Edge[] = {1, 2, 0, -1}
Output: 3
Explanation: 
There is only one cycle in the graph.
(i.e 0->1->2->0)
Sum of the cell index in that cycle 
= 0 + 1 + 2 = 3.
  
Example 2:
Input:
N = 4 
Edge[] = {2, 0, -1, 2}
Output: -1
Explanation:
1 -> 0 -> 2 <- 3
There is no cycle in the graph.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 10^5
-1 < Edge[i] < N
Edge[i] != i

class Solution
{
  public:
  void dfs(int node, vector<int>& Edge, int visited[], int pathVisited[], long long& ans) {
      visited[node] =1;
      pathVisited[node]=1;
      
      if(Edge[node]!=-1) {
          int adjNode = Edge[node];
          if(!visited[adjNode]) {
              dfs(adjNode, Edge, visited, pathVisited, ans);
          }
          else if(pathVisited[adjNode]) {
              int curr = adjNode;
              long long sum = 0;
              do {
                  sum+=curr;
                  curr=Edge[curr];
              }while(curr!=adjNode);
              ans=max(ans, sum);
          }
      }
      pathVisited[node]=0; 
  }
  long long largestSumCycle(int N, vector<int> Edge)
  {
    // code here
    long long maxSumCycle = -1;
    int visited[N]={0};
    int pathVisited[N]={0};
    for(int i=0;i<N;i++) {
        if(!visited[i]) 
            dfs(i, Edge, visited, pathVisited, maxSumCycle);
    }
    return maxSumCycle;
  }
};
