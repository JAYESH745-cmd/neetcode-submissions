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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* r1=reverse(l1);
        // ListNode* r2=reverse(l2);
        ListNode* sum=new ListNode(-1);
        ListNode* temp=sum;
        int a=0;
        int b=0;
        int p=1;
        while(l1){
            a+=l1->val*p;
            l1=l1->next;
            p*=10;
        }
        p=1;
        while(l2){
            b+=l2->val*p;
            l2=l2->next;
            p*=10;
        }
        int v=a+b;
        cout<<v;
        if(v==0) {
            ListNode* t=new ListNode(0);
            temp->next=t;
        }
        p=10;
       while(v){
        ListNode* t=new ListNode(v%p);
        temp->next=t;
        temp=temp->next;
        v/=10; 
       }
        return sum->next;
    }
};
