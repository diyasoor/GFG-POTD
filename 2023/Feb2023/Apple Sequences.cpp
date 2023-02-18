There is a string of size n containing only 'A' and 'O'. 'A' stands for Apple, 
and 'O' stands for Orange. We have m number of spells, each spell allows us 
to convert an orange into an apple.

Find the longest sequence of apples you can make, given a string and the value of m.

Example 1:
Input:
N = 5
M = 1
arr[] = 'AAOAO'
Output: 4 
Explanation: Changing the orange at 
3rd position into an apple gives 
us the maximum possible answer.

Example 2:
Input:
N = 5
M = 1
arr = 'AOOAO'
Output: 2
Explanation: Changing any orange into 
an apple will give us a sequence 
of length 2.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= m <= n <= 10^6

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here 
        int l=0, r=0, maxLen=0;
        unordered_map<char, int> map;
        while(r < n) {
            map[arr[r]]++;
            // if O count is greater than m 
            // shrink the window and eliminate 
            // the char from map
            while(map['O'] > m) {
                map[arr[l]]--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};
