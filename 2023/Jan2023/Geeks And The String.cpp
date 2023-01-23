Our geek loves to play with strings, Currently, he is trying to reduce the size of 
a string by recursively removing all the consecutive duplicate pairs. In other words, 
He can apply the below operations any number of times.

Remove all the consecutive duplicate pairs and concatenate the remaining string to replace the original string.
Your task is to find the string with minimum length after applying the above operations.

Note: If the string length become zero after applying operations, return "-1" as a string.


Example 1:
Input: aaabbaaccd
Output: ad
Explanation: 
Remove (aa)abbaaccd =>abbaaccd
Remove a(bb)aaccd => aaaccd
Remove (aa)accd => accd
Remove a(cc)d => ad

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= |str| <= 10^4

class Solution {
  public:
    string removePair(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++) {
            if(!st.empty()) {
                if(st.top()==s[i]) {
                    st.pop();
                    continue;
                }
            }
            st.push(s[i]);
        }
        string ans="";
        while(!st.empty()) {
            char ch=st.top();
            ans = ch + ans;
            st.pop();
        }
        return ans==""?"-1":ans;
    }
};
