You are given the head of a linked list. You have to replace all the values of 
the nodes with the nearest prime number. If more than one prime number exists 
at an equal distance, choose the smallest one.

Example 1:
Input:
2 → 6 → 10
Output:
2 → 5 → 11
Explanation:
The nearest prime of 2 is 2 itself.
The nearest primes of 6 are 5 and 7,
since 5 is smaller so, 5 will be chosen.
The nearest prime of 10 is 11.
 
Example 2:
Input:
1 → 15 → 20
Output:
2 → 13 → 19
Explanation:
The nearest prime of 1 is 2.
The nearest primes of 15 are 13 and 17,
since 13 is smaller so, 13 will be chosen.
The nearest prime of 20 is 19.

Expected Time Complexity: O(number of nodes * sqrt(value of node)).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ Number of Nodes ≤ 10^4 
1 ≤ Value on Node ≤ 10^4 

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/
// Time: O(n* sqrt(n))
class Solution{
public:
    bool isPrime(int n) {
        if(n==1) return false;
        if(n==2 || n==3) return true;
        for(int i=2;i*i<=n;i++) 
            if(n%i==0) return false;
        return true;
    }
    Node *primeList(Node *head){
        Node* temp=head;
        
        while(temp) {
            if(temp->val==1) {
                temp->val=2;
                temp=temp->next;
                continue;
            }
            
            int x=temp->val, y=temp->val;
            while(!isPrime(x)) x--;
            while(!isPrime(y)) y++;
            
            if(temp->val-x > y-temp->val) temp->val=y;
            else temp->val=x;
            
            temp=temp->next;
        }
        return head;
    }
};

// Optimization: sieve of eratosthenes
// Time: O(loglogn + n)
// Space: O(n)
class Solution{
public:
    Node *primeList(Node *head){
        
        // Optimization: sieve of eratosthenes
        int n=100000;
        vector<bool> isPrime(n, true);

        for(int i=2;i*i<=n;i++) {
            if(isPrime[i]) {
                for(int j=i*i; j<n; j+=i) 
                    isPrime[j]=false;
            }
        }
        // Optimization: sieve of eratosthenes
        
        Node* temp=head;
        
        while(temp) {
            if(temp->val==1) {
                temp->val=2;
                temp=temp->next;
                continue;
            }
            
            int x=temp->val, y=temp->val;
            while(!isPrime[x]) x--;
            while(!isPrime[y]) y++;
            
            if(temp->val-x > y-temp->val) temp->val=y;
            else temp->val=x;
            
            temp=temp->next;
        }
        return head;
    }
};
