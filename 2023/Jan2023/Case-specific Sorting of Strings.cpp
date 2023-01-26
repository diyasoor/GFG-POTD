Given a string S consisting of only uppercase and lowercase characters. The task is to 
sort uppercase and lowercase letters separately such that if the ith place in the original 
string had an Uppercase character then it should not have a lowercase character after 
being sorted and vice versa.

Example 1:
Input:
N = 12
S = defRTSersUXI
Output: deeIRSfrsTUX
Explanation: Sorted form of given string
with the same case of character as that
in original string is deeIRSfrsTUX

Expected Time Complexity: O(Nlog(N)).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 10^5

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        // 1. Sort the string as per ASCII value
        string temp=str;
        sort(temp.begin(), temp.end());
        
        // 2. find the upper and lower pointer
        int up=-1, lo=-1;
        // find upper pointer
        if(temp[0]<97) up=0; // there exist some upper char
        
        // find lower pointer
        for(int i=0;i<str.size();i++) {
            if(temp[i]>=97) {
                lo=i;
                break;
            }
        }
        
        // 3. rearrange the output string
        string ans="";
        for(int i=0;i<str.size();i++) {
            
            if(str[i] < 97) {
                ans+=temp[up];
                up++;
            }
            else {
                ans+=temp[lo];
                lo++;
            }
        }
        return ans;
    }
};
