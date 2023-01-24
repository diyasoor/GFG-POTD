Geek is extremely punctual but today even he is not feeling like doing his homework 
assignment. He must start doing it immediately in order to meet the deadline. For 
the assignment, Geek needs to type a string s.
To reduce his workload, he has decided to perform one of the following two operations 
till he gets the string.

Append a character at the end of the string.
Append the string formed thus far to the end of the string. (This can not be done 
more than once.)
Help Geek find the minimum operations required to type the given string.


Example 1:
Input: s = abcabca
Output: 5
Explanation: a -> ab -> abc -> abcabc -> abcabca

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 10^3

class Solution {
  public:
    int minOperation(string s) {
        // code here
        int n=s.size();
        for(int i=n/2;i>=0;i--) {
            string front=s.substr(0, i+1);
            string back=s.substr(i+1, i+1);
            if(front==back) return n-i;
        }
        return n;
    }
};
