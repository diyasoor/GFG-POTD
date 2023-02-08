Suppose you have a Matrix size n*n, and given an integer k and a set of coordinates arr 
of size k*2. Initially, the matrix contains only 0. You are given k tasks and for each 
task, you are given two coordinates (r = arr[i][0],c = arr[i][1]) [1 based index r and c]. 
Where coordinates (r,c) denotes rth row and cth column of the given matrix.

You have to perform each task sequentially in the given order. For each task, You have 
to put 1 in all rth row cells and all cth columns cells.

After each task, You have to calculate the number of 0 present in the matrix and return it.

Example 1:

Input:
n = 3, k= 3
arr =
{{2, 2},
 {2, 3},
 {3, 2}}
Output: 4 2 1
Explanation: 
After 1st Operation, all the 2nd row
and all the 2nd column will be filled by
1. So remaning cell with value 0 will be 4
After 2nd Operation, all the 2nd row and all
the 3rd column will be filled by 1. So 
remaning cell with value 0 will be 2.
After 3rd Operation cells having value 0 will
be 1.
  
Example 2:
Input:
n = 2, k = 2
arr = 
{{1, 2},
 {1, 1}}
Output: 1 0
Explanation: 
After 1st Operation, all the 1st row and 
all the 2nd column will be filled by 1. 
So remaning cell with value 0 will be 1.
After 2nd Operation, all the 1st row and 
all the 1st column will be filled by 1. 
So remaning cell with value 0 will be 0. 

Expected Time Complexity: O(k).
Expected Auxiliary Space: O(n+n+k).

Constraints:
1 <= n, k <= 10^5
1 <= r, c <= n

class Solution{
  public:
  vector<long long int> countZero(int n, int K, vector<vector<int>>& arr){
        //Code Here
        unordered_set<int> row;
        unordered_set<int> col;
        vector<long long int> ans(K,0);
        // long long int n =N;
        long long int total_zero=n*n;
        long long int total_one,r,c;
        for(int i=0;i<K;i++) {
            row.insert(arr[i][0]);
            col.insert(arr[i][1]);
            r=row.size();
            c=col.size();
            total_one = ((r+c)*n) - (r*c);
            ans[i]=total_zero - total_one;
        }
        return ans;
  }
};
