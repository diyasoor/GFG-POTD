Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled form of S1.

Scrambled string: Given string str, we can represent it as a binary tree by partitioning it into two non-empty substrings recursively.
Below is one possible representation of str = coder:
 
To scramble the string, we may choose any non-leaf node and swap its two children. 
Suppose, we choose the node co and swap its two children, it produces a scrambled string ocder.
Similarly, if we continue to swap the children of nodes der and er, it produces a scrambled string ocred.

Note: Scrambled string is not the same as an Anagram.

Print "Yes" if S2 is a scrambled form of S1 otherwise print "No".

Example 1:

Input: S1="coder", S2="ocder"
Output: Yes
Explanation: ocder is a scrambled 
form of coder.

    ocder
   /    \
  oc    der
 / \    
o   c  

As "ocder" can represent it 
as a binary tree by partitioning 
it into two non-empty substrings.
We just have to swap 'o' and 'c' 
to get "coder".
Example 2:

Input: S1="abcde", S2="caebd" 
Output: No
Explanation: caebd is not a 
scrambled form of abcde.

Expected Time Complexity: O(N^2)
Expected Auxiliary Space: O(N^2)

Constrains: 

S1.length = S2.length
S1.length<=31
S1 and S2 consist of lower-case English letters.
  

class Solution{
    public:
    unordered_map<string, bool> map;
    bool isScramble(string S1, string S2){
        //code here
        if(S1==S2) return map[S1+"$"+S2]=true;
        else if(S1.size()==1) return false;
        
        if(map.find(S1+"$"+S2)!=map.end()) return map[S1+"$"+S2];
        
        int n=S1.size();
        for(int k=1;k<=n-1;k++) {
            bool case1 = isScramble(S1.substr(0,k), S2.substr(0,k)) &&
                         isScramble(S1.substr(k,n-k), S2.substr(k,n-k));
                         
            bool case2 = isScramble(S1.substr(0,k), S2.substr(n-k,k)) &&
                         isScramble(S1.substr(k,n-k), S2.substr(0,n-k));
                         
            if(case1 || case2) return map[S1+"$"+S2]=true;
        }
        return map[S1+"$"+S2]=false;

    }    
};
