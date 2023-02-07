Given an array arr[] consisting of n integers, find the length of the 
longest subarray with positive (non zero) product.

Example 1:
Input:
arr[] ={0, 1, -2, -3, -4} 
Output: 3
Explanation: 
The longest subarray with positive product is: 
{1, -2, -3}.Therefore, the required length is 3.
 
Example 2:
Input:
arr[]={-1, -2, 0, 1, 2}
Output: 2
Explanation:
The longest subarray with positive products 
are: {-1, -2}, {1, 2}. Therefore, the required 
length is 2.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
 1<=n<=10^5
-109<=arr[i]<=10^9

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
           int maxLen=0, currLen=0, product=1;
           
           for(int i=0;i<n;i++) {
               if(arr[i]==0) {
                   currLen=0, product=1;
                   continue;
               }
               else if(arr[i]>0) product*=1;
               else product*=-1;
               currLen++;
               if(product>0) maxLen = max(maxLen, currLen);
           }
           currLen=0, product=1;
           for(int i=n-1;i>=0;i--) {
               if(arr[i]==0) {
                   currLen=0, product=1;
                   continue;
               }
               else if(arr[i]>0) product*=1;
               else product*=-1;
               currLen++;
               if(product>0) maxLen = max(maxLen, currLen);
           }
           return maxLen;
        }
};
