Given N nodes of a tree and a list of edges. Find the minimum number of nodes 
to be selected to light up all the edges of the tree.
An edge lights up when at least one node at the end of the edge is selected.

Example 1:
Input: N = 6
edges[] = {(1,2), (1,3), (2,4), (3,5), (3,6)}
Output: 2
Explanation: Selecting nodes 2 and 3 lights
up all the edges.

Example 2:
Input: N = 3
arr[] = {(1,2), (1,3)}
Output: 1
Explanation: Selecting Node 1 
lights up all the edges.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 10^5
1 ≤ edges ≤ N
Given graph is a valid tree.

class Solution{
  public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited,int& ans) {
        visited[node]=1;
        bool selectNode=false;
        
        for(auto adjNode: adj[node]) {
            if(visited[adjNode]!=1 && !dfs(adjNode, adj, visited,ans)) {
                selectNode=true;
            }
        }
        if(selectNode) ans++;
        return selectNode;
    }
    int countVertex(int N, vector<vector<int>>edges){
        // code here
        vector<vector<int>> adj(N+1);
        vector<int> visited(N+1, 0);
        for(auto e:edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans=0;
        dfs(1, adj, visited, ans);
        return ans;
    }
};
