The task is to find the second smallest number with a given sum of 
digits as S and the number of digits as D.
Example 1:
Input:
S = 9 
D = 2
Output: 27
Explanation:
18 is the smallest number possible with sum = 9
and total digits = 2, Whereas the second
smallest is 27.

Example 2:
Input:
S = 16
D = 3
Output: 178
Explanation:
169 is the smallest number possible with sum is
16 and total digits = 3, Whereas the second
smallest is 178.

Expected Time Complexity: O(D)
Expected Space Complexity: O(1)

Constraints:
1 ≤ S ≤ 10^5
1 ≤ D ≤ 10^5

class Solution{   
  public:
    string secondSmallest(int S, int D){
        // code here 
        if(S >= D*9) return "-1";
        
        S=S-1;
        vector<char> arr(D);
        for(int i=D-1;i>0;i--) {
            if(S > 9) {
                arr[i] = 9+'0';
                S-=9;
            }
            else {
                arr[i] = S+'0';
                S=0;
            }
        }
        arr[0]=1+S+'0';
        
        int target=D-1;
        for(int i=target;i>=0;i--) {
            if(arr[i]=='9') target=i;
            else break;
        }
        arr[target]--;
        arr[target-1]++;
        string ans="";
        for(auto x:arr) ans+=x;
        return ans;
        
    }
};
