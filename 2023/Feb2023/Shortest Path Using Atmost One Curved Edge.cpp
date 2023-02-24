Given an undirected connected graph of n vertices and list of m edges in a graph 
and for each pair of vertices that are connected by an edge. 

There are two edges between them, one curved edge and one straight edge i.e. the 
tuple (x, y, w1, w2) means that between vertices x and y, there is a straight 
edge with weight w1 and a curved edge with weight w2.

You are given two vertices a and b and you have to go from a to b through a series 
of edges such that in the entire path you can use at most 1 curved edge. Your task 
is to find the shortest path from a to b satisfying the above condition. If there 
is no path from a to b, return -1.

Example 1:
Input:
n = 4, m = 4
a = 2, b = 4
edges = {{1, 2, 1, 4}, {1, 3, 2, 4},
         {1, 4, 3, 1}, {2, 4, 6, 5}}
Output:
2
Explanation:
We can follow the path 2 -> 1 -> 4.
This gives a distance of 1+3 = 4 if we follow
all straight paths. But we can take the curved
path  from 1 -> 4, which costs 1. This
will result in a cost of 1+1 = 2

Example 2:
Input:
n = 2, m = 1
a = 1, b = 2
edges = {{1, 2, 4, 1}}
Output :
1
Explanation:
Take the curved path from 1 to 2 which costs 1. 

Expected Time Complexity: O((m+n)log(n))
Expected Auxiliary Space: O(n+m)

Constraints:
1 ≤ n,m ≤ 10^5
1 ≤ a,b ≤ n
weight of edges ≤ 10^4

class Solution {
  public:
  vector<int> dijkstra(int src, int n, vector<vector<int>>adj[]) {
      vector<int> distance(n+1, INT_MAX);
      distance[src]=0;
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
      // {dest node, dist}
      pq.push({0, src});
      while(!pq.empty()) {
          auto temp = pq.top();
          pq.pop();
          int node=temp.second;
          int dist=temp.first;
          
          for(int i=0;i<adj[node].size();i++) {
              int adjNode = adj[node][i][0];
              int adjDist = adj[node][i][1];

              if(dist + adjDist < distance[adjNode]) {
                  distance[adjNode] = dist + adjDist;
                  pq.push({dist + adjDist, adjNode});
              }
          }
      }
      return distance;
  }
  
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj[n+1];
        for(auto e:edges) {
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        
        vector<int> forA = dijkstra(a,n,adj);
        vector<int> forB = dijkstra(b,n,adj);
        
        int ans = forA[b];
        if(ans==INT_MAX) return -1;
        
        for(auto x:edges) {
            if(forA[x[0]]!=INT_MAX and forB[x[1]]!=INT_MAX) {
                ans=min(ans, forA[x[0]] + x[3] + forB[x[1]]);
            }
            
            if(forA[x[1]]!=INT_MAX and forB[x[0]]!=INT_MAX) {
                ans=min(ans, forA[x[1]] + x[3] + forB[x[0]]);
            }
            
        }
        
        return ans;
    }
};
