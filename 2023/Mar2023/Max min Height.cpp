You have a garden with n flowers lined up in a row. The height of ith flower is ai units. 
You will water them for k days. In one day you can water w continuous flowers (you can do 
this only once in a single day). Whenever you water a flower its height increases by 1 unit. 
You need to maximize the height of the smallest flower all the time.

Example 1:

Input:
n=6, k=2, w=3
a[]={2,2,2,2,1,1}
Output: 2
Explanation:
Water last three flowers for first day & 
first three flowers for second day.The 
new heights will be {3,3,3,3,2,2}

Example 2:
Input:
n=2, k=5, w=1
a[]={5,8}
Output: 9
Explanation:
For the first four days water the first flower then
water the last flower once.

Expected Time Complexity: O(NLogN)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n<= 10^5
1<=w<=n
1<=k<=10^5
1 <= a[i] <= 10^9

class Solution
{
    public:
        bool waterPlants(int n, int k, int w, vector<int>a, long long int h) {
            for(int i=0;i<n;i++) {
                if(a[i]<h) {
                    int reqDays=h-a[i];
                    k-=reqDays;
                    if(k < 0) return false;
                    a[i]=h;
                    // for other w-1 plants
                    for(int j=i+1;j<min(n,i+w);j++) 
                        a[j]+=reqDays;
                }
            }
            return true;
        }
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
        {
            // code here
            int left=*min_element(a.begin(), a.end()), right;
            right=left+k;
            
            long long int ans=0;
            while(left<=right) {
                long long int mid=(left+right)/2;
                if(waterPlants(n,k,w,a,mid)) {
                    ans=mid;
                    left=mid+1; // as we want to maximize the ans
                }
                else right=mid-1;
            }
            return ans;
        }
};
