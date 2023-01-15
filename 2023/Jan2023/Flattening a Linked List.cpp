Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
  
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/
  
Time Complexity: O(N), where N is the total number of nodes present, We are visiting all the nodes present in the given list.
Space Complexity: O(1), We are not creating new nodes or using any other data structure.

class Solution {
public:

    Node *merge(Node *a, Node *b) {
        Node* temp = new Node(0); // dummy node
        Node* head = temp;
        
        while(a && b) {
            if(a->data < b->data) {
                temp->bottom = a;
                temp = temp->bottom;
                a = a->bottom;
            }
            else {
                temp->bottom = b;
                temp = temp->bottom;
                b = b->bottom;
            }
        }
        if(a) temp->bottom = a;
        else temp->bottom = b;
        
        return head->bottom;
    } 
    Node *flatten(Node *root)
    {
        // Your code here
        if(!root || !root->next) return root;
        
        root->next = flatten(root->next);
        
        root = merge(root, root->next);
        
        return root;
    }
};
