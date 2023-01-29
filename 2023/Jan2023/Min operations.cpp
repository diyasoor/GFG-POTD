Given two numbers a and b. In one operation you can pick any non negative integer 
x and either of a or b. Now if you picked a then replace a with a&x else if you 
picked b then replace b with b&x.

Return the minimum number of operation required to make a and b equal.

Note: Here & represents bitwise AND operation.

Example 1:

Input:
a = 5, b = 12
Output:
2
Explanantion:
In first operation replace 
a = a&4 = 4
after that replace 
b = b&6 = 4
Hence both are same after applying two
operations.
Example 2:

Input: 
a = 100, b = 100
Output: 
0
Explanation: Already same.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
Constraints:
0 ≤ a, b ≤ 10^9

class Solution {
  public:
    int solve(int a, int b) {
        // code here
        if(a==b) return 0;
        // 6&2==min(6,2) only one move required
        if(a&b==min(a,b)) return 1;
        // when a&b < min(a,b) in range[0,min(a,b)]
        // then 5&12=4 so then we always required 2 moves
        // why? 5&4=4 and 12&4=4 whatever be the value of a or b
        // we will always get x while performing bitwise and with a & b
        // so x is in range [0, 5] here x=4
        else return 2;
    }
};
