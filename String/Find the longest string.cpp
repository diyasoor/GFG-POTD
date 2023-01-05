Given an array of strings arr[]. You have to find the longest string which is lexicographically 
smallest and also all of its prefix strings are already present in the array.

Example 1:
Input: ab a abc abd
Output: abc
Explanation: We can see that length of the longest 
string is 3. And there are two string "abc" and "abd"
of length 3. But for string "abc" , all of its prefix
"a" "ab" "abc" are present in the array. So the
output is "abc".
  
class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        set<string> set;
        sort(words.begin(), words.end());
        
        string ans="";
        set.insert("");
        
        for(auto str: words) {
            if(set.count(str.substr(0,str.size()-1))) {
                set.insert(str);
                if(str.size() > ans.size()) ans=str;
            }
        }
        return ans;
    }
};
