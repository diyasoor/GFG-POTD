Given a binary tree. The task is to find the maximum GCD of the siblings of 
this tree. You have to return the value of the node whose two immediate children 
has the maximum gcd.
If there are multiple such nodes, return the node which has the maximum value.

Siblings: Nodes with the same parent are called siblings.

GCD (Greatest Common Divisor) of two positive integers is the largest positive 
integer that divides both numbers without a remainder.

Note:
Return 0 if input tree is empty i.e level of tree is -1.
Consider those nodes which have a sibling.
Return 0 if no such pair of siblings found.
 

Example 1:

Input:
              4
            /   \
           5     2
                /  \
               3    1
              /  \
             6   12

Output: 3
Explanation: For the above tree, the maximum
GCD for the siblings is formed for nodes 6 and 12
for the children of node 3.
 

Example 2:

Input: 
            1
          /   \
        3      5
      /  \    /  \
     6    9  4    8

Output: 5
Explanation: For the above tree, the maximum
GCD for the siblings is formed for nodes 4 and 8
for the children of node 5.
  
Expected Time Complexity: O(|Number of nodes|) .
Expected Auxiliary Space: O(1) .

Constraints:
1 <= Number of nodes <= 10^5
1 <= Data of a node <= 10^5

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


class Solution
{
public:
    int findGCD(int a, int b) {
        if(a==0) return b;
        return findGCD(b%a, a);
    }
    int dfs(Node* root, int& ans,int& maxGcd) {
        if(!root) return 0;
        
        int left = dfs(root->left, ans, maxGcd);
        int right = dfs(root->right, ans, maxGcd);
        
        if(left && right) {
            int gcd = findGCD(left, right);
            if(gcd == maxGcd ) {
                ans = max(ans, root->data);
            } 
            else if(gcd > maxGcd){
                maxGcd = max(maxGcd, gcd);
                ans = root->data;
            }
        }
        return root->data;
    }
    int maxGCD( Node* root)
    {
        //code here
        int ans=0, maxGcd=0;
        
        dfs(root, ans, maxGcd);
        return ans;
    }
};
