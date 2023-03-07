Given a Binary Tree having positive and negative nodes. Find the maximum 
sum of a level in the given Binary Tree.

Example 1:
Input :               
             4
          /    \
         2     -5
        / \    / \
      -1   3  -2  6
Output: 6
Explanation :
Sum of all nodes of 0'th level is 4
Sum of all nodes of 1'th level is -3
Sum of all nodes of 2'th level is 6
Hence maximum sum is 6

Example 2:
Input :          
            1
          /   \
         2     3
        / \     \
       4   5     8
                / \
               6   7  
Output :  17
Explanation: Maximum sum is at level 2.

Expected Time Complexity: O(N), where N is no of node.
Expected Auxiliary Space: O(W), Where W is the max width of the tree.

Constraints:
1 ≤ N ≤ 10^4

class Solution{
  public:
    /*You are required to complete below method */
    int maxLevelSum(Node* root) {
        // Your code here
        queue<Node*> q;
        q.push(root);
        int maxSum=INT_MIN;
        while(!q.empty()) {
            int size=q.size();
            int currSum=0;
            while(size-- > 0) {
                auto temp=q.front();
                q.pop();
                currSum+=temp->data;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            maxSum=max(maxSum, currSum);
        }
        return maxSum;
    }
};
