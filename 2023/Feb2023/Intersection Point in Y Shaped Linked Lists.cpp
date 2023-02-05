Given two singly linked lists of size N and M, write a program to 
get the point where two linked lists intersect each other.

Example 1:
Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15
Explanation:
Y ShapedLinked List

Example 2:
Input: 
Linked List 1 = 4->1->common
Linked List 2 = 5->6->1->common
common = 8->4->5->NULL
Output: 8
Explanation: 

4              5
|              |
1              6
 \             /
  8   -----  1 
   |
   4
   |
  5
  |
  NULL       

Challenge : Try to solve the problem without using any extra space.
Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)
  
Constraints:
1 ≤ N + M ≤ 2*10^5
-1000 ≤ value ≤ 1000
  
class Solution
{
public:
    int intersectPoint(Node* head1, Node* head2)
    {
        // Your Code Here
        // in case of one node the distance of head1 to common + 
        // distance of head2 to common + distance from common to null
        // is equal to the distance in case of the other node
        
        Node* pointLL1 = head1, *pointLL2 = head2;
        
        while(pointLL1!=pointLL2) {
            if(pointLL1->next) 
                pointLL1=pointLL1->next;
            else pointLL1=head2;
            
            if(pointLL2->next) 
                pointLL2=pointLL2->next;
            else pointLL2=head1;
        }
        return pointLL1->data;
    }
};
