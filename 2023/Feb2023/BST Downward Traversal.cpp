Given a Binary Search Tree and a target value. You have to find the node whose data is 
equal to target and return the sum of all descendant node's data which are vertically 
below the target node. Initially you are at the root node.
Note: If target node is not present in bst then return -1.

Example 1:
Input:
        25
      /    \
    20     35
   / \     / \
 15  22  30   45
           \
           32
Target = 35
Output: 32
Explanation: Vertically below 35 is 32.
Example 2:
        25
      /    \
    20     35
   / \     / \
 15  22  30   45
           \
           32
Input:
Target = 25
Output: 52
Explanation: Vertically below 25 is 22, 30 and their sum is 52.

Expected Time Complexity: O( n ), n is number of nodes.
Expected Auxiliary Space: O(Height of the tree).

Constraints:
1 <= n < 10^6
1 <= target <= n
1 <= node.data < 10^6

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
public:
    Node* findTargetNode(Node *root, int target) {
        if(!root) return NULL;
        if(root->data==target) return root;
        if(root->data > target) findTargetNode(root->left, target);
        else if(root->data < target) findTargetNode(root->right, target);
    }
    void findBelowSum(Node *node, int level, int& sum) {
        if(!node) return;
        if(level==0) sum+=node->data;
        if(node->left) findBelowSum(node->left, level-1, sum);
        if(node->right) findBelowSum(node->right, level+1, sum);
    }
    long long int verticallyDownBST(Node *root,int target){
        // Code here
        Node *targetNode = findTargetNode(root,target);
        if(!targetNode) return -1;
        int belowSum=0;
        findBelowSum(targetNode, 0, belowSum);
        return belowSum - targetNode->data;
    }
};
