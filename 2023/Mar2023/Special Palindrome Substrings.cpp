Given two strings s1 and s2, The task is to convert s1 into a palindrome such 
that s1 contain s2 as a substring in a minimum number of operation.
In a single operation, we can replace any word of s1 with any character.

Note: If it is not possible to convert s1 such that it is a palindrome as well 
as contains substring of s2, then return -1.

Example 1:
Input:
s1="abaa" s2="bb"
Output: 1
Explanation:
we can replace s1[2]='a' with 'b'.
So the new s1 will be like "abba",
having s2 as a substring.

Example 2:
Input:
s1="abbd" s2="mr"
Output: 4
Explanation:
1st: s1="mrbd" --> 2 operations (this is the 
minimum operation to make s2 a substring of s1) 
2nd: s1="mrrm" --> 2 operations 
(this is the minimum operation to make s1 palindrome)

Expected Time Complexity: O(N*M) [N: size of s1 and M: size of s2]
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ |s2| ≤ |s1| ≤  1000
  
class Solution{
    //Complete the function and return minimum number of operations
    public:
    int specialPalindrome(string s1, string s2){
        //Code Here
        int n1=s1.size(), n2=s2.size();
        if(n1 < n2) return -1;
        
        int ans=INT_MAX;
        for(int i=0;i<n1-n2+1; i++) {
            string temp = s1.substr(0,i) + s2 + s1.substr(i+n2);
            
            int cost=0;
            
            for(int j=i;j<i+n2;j++) {
                if(s1[j]!=temp[j]) cost++;
            }
            // for(char x:temp) cout<<x<<" ";
            // cout<<cost<<" "<<endl;
            
            bool isPalindrome=true;
            for(int j=0;j<ceil(n1/2.0);j++) {
                
                if((j<i || j>=i+n2) && temp[j]!=temp[n1-j-1]) 
                    cost++;
                else if((n1-i-1<j || n1-i-n2-1 >= j) && temp[j]!=temp[n1-j-1])
                    cost++;
                else if(temp[j]!=temp[n1-j-1]) {
                    isPalindrome=false;
                    break;
                }
            }
            
            if(isPalindrome) ans=min(ans, cost);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
