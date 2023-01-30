Given two strings A and B. Find minimum number of times A has to be repeated such that 
B is a Substring of it. If B can never be a substring then return -1.

Example 1:
Input:
A = "abcd"
B = "cdabcdab"
Output: 3
Explanation:
Repeating A three times (abcdabcdabcd),
B is a substring of it. B is not a substring
of A when it is repeated less than 3 times.
  
Example 2:
Input:
A = "ab"
B = "cab"
Output : -1
Explanation:
No matter how many times we repeat A, we can't
get a string such that B is a substring of it.

Expected Time Complexity: O(|A| * |B|)
Expected Auxiliary Space: O(|B|)
  
Constraints:
1 ≤ |A|, |B| ≤ 10^3
String A and B consists of lower case alphabets

class Solution {
  public:
    bool checkSubstring(string temp, string B) {
        int m=temp.size(), n=B.size();
        
        for(int i=0;i<=m-n;i++) {
            int j=0;
            for( ;j<n;j++) {
                if(temp[i+j]!=B[j]) 
                    break;
            }
            if(j==n) return true;
        }
        return false;
    }
    int minRepeats(string A, string B) {
        // code here
        int repCnt=1;
        string temp = A;
        while(B.size() > temp.size()) {
            temp += A;
            repCnt++;
        }
        if(checkSubstring(temp, B)) return repCnt;
        if(checkSubstring(temp+A, B)) return repCnt+1;
        return -1;
    }
};
