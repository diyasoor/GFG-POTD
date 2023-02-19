Two of the nodes of a Binary Search Tree (BST) are swapped. Fix 
(or correct) the BST by swapping them back. Do not change the 
structure of the tree.
Note: It is guaranteed than the given input will form BST, 
except for 2 nodes that will be wrong.
 
Example 1:
Input:
       10
     /    \
    5      8
   / \
  2   20
Output: 1
Explanation:
 
Example 2:
Input:
         11
       /    \
      3      17
       \    /
        4  10
Output: 1 
Explanation: 
By swapping nodes 11 and 10, the BST 
can be fixed.

Expected Time Complexity : O(Number of nodes)
Expected Auxiliary Space : O(logN), N = number of nodes
 
Constraints:
1 <= Number of nodes <= 10^5

class Solution {
  public:
    void inorder(Node *root, Node *&prev, Node *&first,Node *&middle, Node *&last) {
        if(!root) return;
        
        inorder(root->left, prev, first, middle, last);
        
        if(prev && (root->data < prev->data)) {
            // first violation
            if(!first) {
                first = prev;
                middle = root;
            }
            // second violation
            else last = root;
        }
        prev=root;
        
        inorder(root->right, prev, first, middle, last);
    }
    struct Node *correctBST(struct Node *root) {
        // code here
        Node *prev =NULL, *first=NULL, *last=NULL, *middle=NULL;
        // prev = new struct Node(INT_MIN);
        inorder(root, prev, first, middle, last);
        // not adjacent
        if(first && last) swap(first->data, last->data);
        // if the swapped nodes are adjacent
        else if(first && middle) swap(first->data, middle->data);
        
        return root;
    }
};
