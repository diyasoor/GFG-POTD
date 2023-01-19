There is a carpet of a size a*b [length * breadth]. You are given a box of 
size c*d. The task is, one has to fit the carpet in the box in a minimum 
number of moves. 

In one move, you can either decrease the length or the breadth of the 
carpet by half (floor value of its half).

Note: One can even turn the carpet by 90 degrees any number of times,
wont be counted as a move.

Example 1:

Input:
A = 8, B = 13
C = 6, D = 10
Output:
Minimum number of moves: 1
Explanation:
Fold the carpet by breadth, 13/2 i.e. 6, 
so now carpet is 6*8 and can fit fine.
 
Example 2:

Input:
A = 4, B = 8
C = 3, D = 10
Output:
Minimum number of moves: 1
Explanation: Fold the carpet by length , 4/2 i.e. 2,
so now carpet is 2*8 and can fit fine.

Expected Time Complexity: O( max( log(a), log(b) ) ) .
Expected Auxiliary Space: O(1) .

Constrains:
1<= A,B,C,D <= 10^9

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        //code here
        // case:1
        int len=A, wid=B, cnt=0;
        while(len > C || wid > D) {
            if(len > C) { len/=2; cnt++; }
            if(wid > D) { wid/=2; cnt++; }
        }
        int prevCnt=cnt;
        // case:2 90deg rotate
        len=B, wid=A, cnt=0;
        while(len > C || wid > D) {
            if(len > C) { len/=2; cnt++; }
            if(wid > D) { wid/=2; cnt++; }
        }
        return min(cnt, prevCnt);
    }
};
