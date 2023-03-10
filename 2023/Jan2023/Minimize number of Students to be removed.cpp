Question:
N Students of different heights are attending an assembly. The heights of the students 
are represented by an array H[]. The problem is that if a student has less or equal 
height than the student standing in front of him, then he/she cannot see the assembly. 
Find the minimum number of students to be removed such that maximum possible number of 
students can see the assembly.
Example :
Input:
N = 6
H[] = {9, 1, 2, 3, 1, 5}
Output:
2
Explanation:
We can remove the students at 0 and 4th index.
which will leave the students with heights
1,2,3, and 5.

* Using DP: T.C: O(N^2)
class Solution {
  public:
    int removeStudents(int H[], int N) {
        // code here
        vector<int> dp(N+1, 1);
        
        for(int i=N-1; i>=0; i--) {
            for(int j=i+1; j<N; j++) {
                if(H[i] < H[j]) {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }
        
        return N - *max_element(dp.begin(), dp.end());
    }
};

* Using lower_bound(): T.C: O(NlogN)
class Solution {
  public:
    int removeStudents(int H[], int N) {
        // code here
        vector<int> dp;
        
        for(int i=0; i<N; i++) {
            auto it = lower_bound(dp.begin(), dp.end(), H[i]);
            if(it==dp.end()) dp.push_back(H[i]);
            else *it = H[i];
        }
        
        return N - dp.size();
    }
};
