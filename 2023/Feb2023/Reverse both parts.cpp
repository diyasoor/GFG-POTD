Given a linked list and a number k. You have to reverse first part of linked 
list with k nodes and the second part with n-k nodes.

Example 1:

Input: 1 -> 2 -> 3 -> 4 -> 5
k = 2
Output: 2 -> 1 -> 5 -> 4 -> 3
Explanation: As k = 2 , so the first part 2
nodes: 1 -> 2 and the second part with 3 nodes:
3 -> 4 -> 5. Now after reversing the first part: 
2 -> 1 and the second part: 5 -> 4 -> 3.
So the output is: 2 -> 1 -> 5 -> 4 -> 3
Example 2:

Input: 1 -> 2 -> 4 -> 3
k = 3
Output: 4 -> 2 -> 1 -> 3
Explanation: As k = 3 , so the first part 
3 nodes: 4 -> 2 -> 1 and the second part
with 1 nodes: 3. Now after reversing the 
first part: 1 -> 2 -> 4 and the 
second part: 3. So the output is: 1 -> 2 -> 4 -> 3
 
Constraints:
1 <= N <= 10^5 
1 <= k < N 

Expected Time Complexity: O(N)
Expected Space Complexity: O(1)

class Solution
{
public:
   
    Node *reverse(Node *head, int k)
    {
        // code here
        // 1->2->3->4->5, k=2, node=5
        Node *curr=head, *prev=NULL, *next=NULL;
        int node=0;
        while(curr) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            node++;
        }
        // prev                      head
        // 5   ->  4  ->  3  ->  2  ->  1
        Node *temp=prev;
        int i=node-k-1;
        while(i--) {
            temp=temp->next;
        }
        // prev         temp         head
        // 5   ->  4  ->  3  ->  2  ->  1
        head->next = prev;
        head = temp->next;
        // prev          temp   head 
        // 5   ->  4  ->  3  ->  2  ->  1
        // |____________________________|
        
        temp->next=NULL;
        return head;
    }
    
};
