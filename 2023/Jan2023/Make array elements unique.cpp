Given an array arr[ ] of N elements, your task is to find the minimum number 
of increment operations required to make all the elements of the array unique. 
ie- no value in the array should occur more than once. In an operation a value 
can be incremented by 1 only.

Example 1:
Input:
N = 3
arr[] = {1, 2, 2}
Output: 1
Explanation:
If we increase arr[2] by 1 then the resulting 
array becomes {1, 2, 3} and has all unique values.
Hence, the answer is 1 in this case.
  
Example 2:
Input: 
N = 4
arr[] = {1, 1, 2, 3}
Output: 3
Explanation: 
If we increase arr[0] by 3, then all array
elements will be unique. Hence, the answer 
is 3 in this case.

Expected Time Complexity: O(N*log(N))
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 10^5 
1 ≤ arr[i] ≤ 10^9

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        long long cnt=0;
        sort(arr.begin(), arr.end());
        for(int i=1;i<N;i++) {
            while(arr[i] <= arr[i-1]) {
                arr[i]++;
                cnt++;
            }
        } 
        return cnt;
    }
};
