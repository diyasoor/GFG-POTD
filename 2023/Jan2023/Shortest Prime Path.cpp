You are given two four digit prime numbers Num1 and Num2. Find the distance 
of the shortest path from Num1 to Num2 that can be attained by altering only 
one single digit at a time. Every number obtained after changing a digit should 
be a four digit prime number with no leading zeros.

Example 1:

Input:
Num1 = 1033 
Num2 = 8179
Output: 6
Explanation:
1033 -> 1733 -> 3733 -> 3739 -> 3779 -> 8779 -> 8179.
There are only 6 steps required to reach
Num2 from Num1, and all the intermediate
numbers are 4 digit prime numbers.
  
Example 2:

Input:
Num1 = 1033 
Num2 = 1033
Output:
0

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)

Constraints:
1000 ≤ Num1,Num2 ≤ 9999
Num1 and Num2 are prime numbers.
  
class Solution{   
  public:
    vector<int> prime;
    Solution() {
        // Sieve of Eratosthenes T.C=O(n*log(log(n)))
        // But here it is little slower with T.C=O(n*logn)
        // link: https://www.geeksforgeeks.org/sieve-of-eratosthenes/
        prime.assign(10000, 1);
        prime[1] = 0;
        for(int i=2;i<10000;i++) {
            for(int j=2*i;j<10000;j+=i) {
                prime[j] = 0;
            }
        }
    }
    int shortestPath(int n1,int n2)
    {   
        // Complete this function using prime vector
        vector<int> visited(10000, -1);
        queue<int> q;
        q.push(n1);
        visited[n1] = 0;
        
        while(!q.empty()) {
            int x=q.front();
            q.pop();
            
            string s=to_string(x);
            // iterating for each index 0-3
            for(int i=0;i<4;i++) {
                string temp = s;
                int start= i==0 ? 1 : 0; // when i=0 & start=0 then it becomes 3-digit no.
                for(int digit=start; digit<10; digit++) {
                    temp[i] = digit + '0';
                    int y = stoi(temp);
                    if(prime[y] && visited[y]==-1) {
                        visited[y] = 1 + visited[x];
                        q.push(y);
                    } 
                }
            }
        }
        return visited[n2];
    }
};
