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
    ListNode* merge(ListNode* list1,ListNode* list2){
        ListNode* ans=new ListNode(-1);
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* temp=ans;
        while(temp1 && temp2){
            if(temp1->val<temp2->val){
                temp->next=temp1;
                temp1=temp1->next;
                temp=temp->next;
            }
            else {
                temp->next=temp2;
                temp2=temp2->next;
                temp=temp->next;
            }
        }
        while(temp1){
            temp->next=temp1;
            temp1=temp1->next;
            temp=temp->next;
        }
        while(temp2){
            temp->next=temp2;
            temp2=temp2->next;
            temp=temp->next;
        }
        return ans->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        while(lists.size()>1){
            vector<ListNode*> m;
            for(int i=0;i<lists.size();i+=2){
                if(i+1<lists.size()) m.push_back(merge(lists[i],lists[i+1]));
                else m.push_back(lists[i]);
            }
            lists=m;
        }
        return lists[0];
    }
};
