Given two integers A and B, the task is to find an integer X such that (X XOR A) 
is minimum possible and the count of set bit in X is equal to the count of set bits in B.

Example 1:

Input: 
A = 3, B = 5
Output: 3
Explanation:
Binary(A) = Binary(3) = 011
Binary(B) = Binary(5) = 101
The XOR will be minimum when x = 3
i.e. (3 XOR 3) = 0 and the number
of set bits in 3 is equal
to the number of set bits in 5.
  
Expected Time Complexity : O(log MAX(A,B))
Expected Auxiliary Space : O(1)
 
Constraints :
1 <= A, B <= 10^9

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int countB;
        int B=b;
        while(B) {
            countB+=B%2;
            B/=2;
        }
        int ans=0, noOfBitsSetinX=countB;
        for(int i=31;i>=0 && noOfBitsSetinX;i--) {
            if(a&(1<<i)) {
                ans |= (1<<i);
                noOfBitsSetinX--;
            } 
        }
        
        for(int i=0;i<=31 && noOfBitsSetinX;i++) {
            if((ans&(1<<i))==0) {
                ans |= (1<<i);
                noOfBitsSetinX--;
            }
        }
        return ans;
    }
};
