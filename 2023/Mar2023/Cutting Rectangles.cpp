Given a rectangle of dimensions L x B find the minimum number (N) of identical 
squares of maximum side that can be cut out from that rectangle so that no 
residue remains in the rectangle. Also find the dimension K of that square.

Example 1:
Input: L = 2, B = 4
Output: N = 2, K = 2
Explaination: 2 squares of 2x2 dimension.

Example 2:
Input: L = 6, B = 3
Output: N = 2, K = 3
Explaintion: 2 squares of 3x3 dimension. 

Expected Time Complexity: O(log min(L, B))
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ L, B ≤ 10^9

class Solution{
public:
    long gcd(long a, long b) {
        if(b==0) return a;
        return gcd(b, a%b);
    }
    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        // code here
        vector<long long int> ans;
        long x=gcd(L,B);
        long squares=(L*B)/(x*x);
        ans.push_back(squares);
        ans.push_back(x);
        return ans;
    }
};
