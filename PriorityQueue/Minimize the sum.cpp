You are given N elements, you can remove any two elements from the list, 
note their sum, and add the sum to the list. Repeat these steps while 
there is more than a single element in the list. The task is to 
minimize the sum of these chosen sums.

Example 1:
Input:
N = 4
arr[] = {1, 4, 7, 10}
Output: 39

Explanation:
Choose 1 and 4, Sum = 1 + 4 = 5.
arr[] = {5, 7, 10} 
Choose 5 and 7, Sum = 5 + (5 + 7) = 17.
arr[] = {12, 10} 
Choose 12 and 10, Sum = 17 + (12 + 10) = 39.
arr[] = {22}

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        // code here
        priority_queue<int, vector<int>, greater<>> pq;
        for(auto x: arr) pq.push(x);
        int sum=0;
        while(pq.size() > 1) {
            int n1 = pq.top();
            pq.pop();
            int n2 = pq.top();
            pq.pop();
            sum += n1+n2;
            pq.push(n1+n2);
        }
        return sum;
    }
};
