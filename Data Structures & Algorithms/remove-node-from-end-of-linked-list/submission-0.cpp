/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* st=head;
       for(int i=0;i<n;i++){
        st=st->next;
       } 
       if(!st) return head->next;
       ListNode* prev;
       ListNode* temp=head;
       while(st){
        prev=temp;
        temp=temp->next;
        st=st->next;
       }
       prev->next=temp->next;
       return head;
    }
};
