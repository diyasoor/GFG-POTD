Given two arrays A[] and B[] of same length N. There are N types of sticks of 
lengths specified. Each stick of length A[i] is present in B[i] units (i=1 to N). 
You have to construct the squares and rectangles using these sticks. Each unit 
of a stick can be used as length or breadth of a rectangle or as a side of square. 
A single unit of a stick can be used only once.

Let S be the sum of lengths of all sticks that are used in constructing squares 
and rectangles. The task is to calulate the maximum possible value of S.

Example 1:
Input:
N = 4
A[] = {3,4,6,5}
B[] = {2,3,1,6}
Output: 38
Explanation: 
There are 2 sticks of length 3.
There are 3 sticks of length 4.
There is a 1 stick of length 6.
There are 6 sticks of length 5.
One square can be made using 4 sticks of
4th kind (5*4=20)
A rectangle can be made using 2 sticks of 
4th kind and 2 sticks of 2nd kind (5*2+4*2=18)
S = 20 + 18 = 38

Example 2:
Input:
N = 1
A[] = {3}
B[] = {2}
Output: 
0
Explanation: 
There are only 2 sticks of length 3 which are 
not enough to make the square or rectangle.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 10^6
1 ≤ A[] ≤ 10^9
1 ≤ B[] ≤ 10^3

class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        // code here
        long minLen=INT_MAX;
        long sticks=0;
        long perimeter=0;
        
        for(int i=0;i<N;i++) {
            if(B[i]%2!=0) B[i]--;
            if(B[i]>=2) minLen=min(minLen, (long)A[i]);
            
            sticks+=B[i];
            perimeter+=(A[i] * B[i]);
        }
        // as we already made the elements even
        // any even num no div by 4 left remainder 2
        if(sticks%4!=0) perimeter-=2*minLen;
        return perimeter;
    }
};
