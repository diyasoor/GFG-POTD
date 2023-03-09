Given a linked list of characters and a string S.Return all the anagrams of the string present 
in the given linked list.In case of overlapping anagrams choose the first anagram from left.

Example 1:
Input: a -> b -> c -> a -> d -> b -> c -> a
S = bac
Output: [a -> b -> c, b -> c -> a]
Explanation: In the given linked list,
there are three anagrams: 
1. a -> b -> c -> a -> d -> b -> c -> a
2. a -> b -> c -> a -> d -> b -> c -> a
3. a -> b -> c -> a -> d -> b -> c -> a
But in 1 and 2, a -> b -> c and b -> c-> a
are ovelapping.So we take a -> b -> c as it
comes first from left.So the output is:
[a->b->c,b->c->a]

Example 2:
Input: a -> b -> d -> c -> a
S = bac
Output: -1 
Explanation: There is no anagrams, so output is -1

Expected Time Complexity: O(N), where N is length of LinkedList
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 10^5
1 <= |S| <= 10^5

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        // code here
        vector<int> mapS(26), mapList(26);
        int chS=0, chList=0;
        for(auto x:s) {
            mapS[x-'a']++;
            if(mapS[x-'a']==1) chS++;
        }
        vector<Node*> ans;
        Node* temp=head;
        while(temp) {
            char ch=temp->data;
            mapList[ch-'a']++;
            if(mapList[ch-'a']==mapS[ch-'a']) chList++;
            while(mapList[ch-'a'] > mapS[ch-'a']) {
                auto d=head->data;
                if(mapList[d-'a']==mapS[d-'a']) chList--;
                mapList[d-'a']--;
                head=head->next;
            }
            if(chS==chList) {
                ans.push_back(head);
                Node* node=temp->next;
                temp->next=NULL;
                temp=node;
                head=node;
                chList=0;
                fill(mapList.begin(), mapList.end(),0);
            }
            else temp=temp->next;
        }
        return ans;
    }
};
