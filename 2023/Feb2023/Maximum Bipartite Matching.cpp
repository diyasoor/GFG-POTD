There are M job applicants and N jobs.  Each applicant has a subset of jobs 
that he/she is interested in. Each job opening can only accept one applicant 
and a job applicant can be appointed for only one job. Given a matrix G with 
M rows and N columns where G(i,j) denotes ith applicant is interested in the 
jth job. Find the maximum number of applicants who can get the job.

Example 1:
Input: 
M = 3, N = 5
G = {{1,1,0,1,1},{0,1,0,0,1},
{1,1,0,1,1}}
Output: 3
Explanation: There is one of the possible
assignment-
First applicant gets the 1st job.
Second applicant gets the 2nd job.
Third applicant gets the 4th job.
  
Example 2:
Input:
M = 6, N = 2
G = {{1,1},{0,1},{0,1},{0,1},
{0,1},{1,0}}
Output: 2
Explanation: There is one of the possible
assignment-
First applicant gets the 1st job.
Second applicant gets the 2nd job.
 
Expected Time Complexity: O(N^3).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N, M ≤ 100
  
class Solution {
public:
    bool dfs(int p, vector<vector<int>>&G, vector<int>& visited, vector<int>& match) {
        for(int j=0;j<G[0].size();j++) {
            if(G[p][j] && !visited[j]) {
                visited[j]=1;
                if(match[j]==-1 || dfs(match[j], G, visited, match)) {
                    match[j]=p;
                    return true;
                }
            }
        }
        return false;
    }
	int maximumMatch(vector<vector<int>>&G){
	    // Code here
	    int person=G.size();
	    int job=G[0].size();
	    vector<int> match(job, -1);
	    int ans=0;
	    for(int i=0;i<person;i++) {
	        vector<int> visited(job, 0);
	        if(dfs(i, G, visited, match))
	            ans++;
	    }
	    return ans;
	}

};
