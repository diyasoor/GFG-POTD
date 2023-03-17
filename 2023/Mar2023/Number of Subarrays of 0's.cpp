You are given an array arr  of length N of 0's and 1's. Find the total 
number of subarrays of 0's

Example 1:
Input:
N = 4
arr[] = {0, 0, 1, 0}
Output: 4
Explanation:
Following are the subarrays of
length 1: {0}, {0}, {0} - 3
length 2: {0, 0} - 1
Total Subarrays: 3 + 1 = 4

Example 2:
Input:
N = 4
arr[] = {0, 0, 0, 0}
Output: 10
Explanation:
Following are the subarrays of
length 1: {0}, {0}, {0}, {0} - 4
length 2: {0, 0}, {0, 0}, {0, 0} - 3
length 3: {0, 0, 0}, {0, 0, 0} - 2
length 4: {0, 0, 0, 0} - 1
Total Subarrays: 4 + 3 + 2 + 1 = 10

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 10^6
0 <= arr[i] <= 1
  
long long int no_of_subarrays(int n, vector<int> &arr) {
    // Write your code here.
    long long int subArrays=0, curr=0;
    for(int i=0;i<n;i++) {
        if(arr[i]==0) curr++;
        else {
            subArrays += (curr*(curr+1))/2;
            curr=0;
        }
    }
    subArrays += (curr*(curr+1))/2;
    return subArrays;
}
