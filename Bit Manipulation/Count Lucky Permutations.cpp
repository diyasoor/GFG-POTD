You are given an array arr[ ] of integers having N elements and a non-weighted 
undirected graph having N nodes and M edges. The details of each edge in the 
graph is given to you in the form of list of list. 
Your task is to find the number of lucky permutations of the given array. 

An array permutation is said to be lucky if for every node Vi  [1 < i < N-1] 
in the array there exists an edge between the nodes Vi and Vi+1 in the given graph.

Example 1:
Input:
N = 3, M = 2
arr = {1, 2, 3}
graph = {{3, 1}, {1, 2}}
Output: 2
Explanation:
All possible permutations of the 
array are as follows-
{1,2,3}: There is an edge between 1 and 
2 in the graph but not betwen 2 and 3.

{2,1,3}: There is an edge between (2,1)
and (1,3) in the graph.

{3,1,2}: There is an edge between (3,1)
and (1,2) in the graph.

Out of the 3 possible permutations, 
2 are lucky. Therefore, answer is 2.

Example 2:
Input:
n = 2, m = 1
arr = {1, 1}
graph = {{1, 2}}
Output : 0
Explanation:
There is no lucky permutation in the 
given graph. 

Your Task:  
You don't need to read input or print anything. Your task is to complete the 
function luckyPermutations() which takes the two integers N and M, an array 
arr[ ] and a list of lists named graph of size M as input parameters and 
returns the count of lucky permutations.

Expected Time Complexity: O(N^2*2^N)
Expected Auxiliary Space: O(N*2^N)


Constraints:
2 ≤ N ≤ 15
1 ≤ M ≤ (N*(N-1))/2
1 ≤  arr[i], graph[i][j] ≤ N 
There are no self loops and repeated edges in the graph.

// dp[i][j] = total no. of permutation that ends with i and contain all set bit of j
// i = node
// j = visited array 
class Solution {
  public:
    long long int luckyPermutations(int N, int M, vector<int> arr,
                                    vector<vector<int>> graph) {
        // Code here
        int adj[N + 1][N + 1] ={{0}};
        for(auto e : graph){
            adj[e[0]][e[1]] = 1;
            adj[e[1]][e[0]] = 1;
        }
        
        long dp[N][(1 << N)];
        for(int i=0;i<N;i++) {
            for(int j=0;j<(1<<N);j++) {
                dp[i][j] = 0;
            }
        }
        
        for(int i=0; i<N; i++){
            dp[i][(1 << i)] += 1;
        }
        
        for(int i=1; i < (1 << N); i++){
            for(int j=0; j<N; j++){
                
                if(((i >> j) & 1) != 0 ){
                    
                    for(int k=0; k<N; k++){
                        
                        if(k != j && arr[k] != arr[j] && ((i >> k) & 1) != 0 && 
                           adj[arr[j]][arr[k]] == 1){
                            dp[j][i] += dp[k][(i ^ (1 << j))];
                        }
                        
                    }
                    
                }
                
            }
        }
        
        long cnt = 0l;
        for(int i=0; i<N; i++){
            cnt += dp[i][(1 << N) - 1];
        }
        
        return cnt;
    }
};
