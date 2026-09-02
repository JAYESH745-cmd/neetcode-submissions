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
    void reorderList(ListNode* head) {
        //finding mid first 
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp=slow->next;
        slow->next=NULL;

        // reverse the second end of list 
        ListNode* curr=temp;
        ListNode* after=NULL;
        ListNode* prev=NULL;

        while(curr){
            after=curr->next;
            curr->next=prev;
            prev=curr;
            curr=after;
        }
        // joining the list 
        temp=head;
        ListNode* gg;
        ListNode* bb;
        while(prev){
            gg=temp->next;
            temp->next=prev;
            bb=prev->next;
            prev->next=gg;
            temp=gg;
            prev=bb; 
        }
    }
};
