Given a singly linked list of N nodes. Find the first node of the loop if the 
linked list has a loop. If a loop is present return the node data of the first 
node of the loop else return -1.

Example 1:

Input:
1 -> 3 -> 2 -> 4 -> 5 -> 6 ---
     |_______________________|
Output: 3
Explanation:
We can see that there exists a loop 
in the given linked list and the first
node of the loop is 3.
  
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 10^5
1 <= Data on Node <= 10^6 
0 <= pos <= N


/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        // your code here
        Node *slow=head;
        Node *fast=head;
        while(fast->next && fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        if(slow!=fast) return -1;
        // start from the start until it reaches 
        // a point where slow==fast
        slow = head;
        while(slow!=fast) {
            slow=slow->next;
            fast=fast->next;
        }
        return slow->data;
    }
};
