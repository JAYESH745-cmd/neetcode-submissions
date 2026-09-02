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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum=new ListNode(-1);
        ListNode* temp=sum;
        int carry=0;

        while(l1 || l2 || carry){
            int c=carry;
            if(l1){
                c+=l1->val;
                l1=l1->next;
            }
            if(l2){
                c+=l2->val;
                l2=l2->next;
            }
            ListNode* dum=new ListNode(c%10);
            temp->next=dum;
            temp=temp->next;
            carry=c/10;
        }
        return sum->next;
    }
};
