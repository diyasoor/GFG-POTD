A special compression mechanism can arbitrarily delete 0 or 
more characters and replace them with the deleted character count.
Given two strings, S and T where S is a normal string and T 
is a compressed string, determine if the compressed string  
T is valid for the plaintext string S. 

Example 1:
Input:
S = "GEEKSFORGEEKS"
T = "G7G3S"
Output:
1
Explanation:
We can clearly see that T is a valid 
compressed string for S.

Example 2:
Input:
S = "DFS"
T = "D1D"
Output :
0
Explanation:
T is not a valid compressed string.

Expected Time Complexity: O(|T|)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ |S| ≤ 10^6
1 ≤ |T| ≤ 10^6
All characters are either capital or numeric.
