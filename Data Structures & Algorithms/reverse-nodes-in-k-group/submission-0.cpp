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
    ListNode* reverse(ListNode* head) {
        if(!head) return NULL;
        ListNode* curr=head;
        ListNode* after=curr;
        ListNode* prev=NULL;

        while(after){
            after=curr->next;
            curr->next=prev;
            prev=curr;
            if(after) curr=after;
        }
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        ListNode* prev=dummy;
        dummy->next=head;
        while(true){
            ListNode* kth=prev;
            for(int i=0;i<k;i++){
                kth=kth->next;
                if(!kth) return dummy->next;
            }
            ListNode* after =kth->next;
            kth->next=NULL;
            ListNode* oldH=prev->next;
            ListNode* newH=reverse(oldH);
            prev->next=newH;
            oldH->next=after;
            prev=oldH;
        }
        return dummy->next;
    }
};
