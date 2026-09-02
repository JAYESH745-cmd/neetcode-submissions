/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* nhead=new Node(-1);
        Node* temp=head;
        Node* ntemp=nhead;
        while(temp){
            Node* c=new Node(temp->val);
            ntemp->next=c;
            ntemp=ntemp->next;
            temp=temp->next;
        }
        nhead=nhead->next;
        temp=head;
        ntemp=nhead;
       // joining both the list
       Node* after1;
       Node* after2;
        while(temp){
            after1=temp->next;
            temp->next=ntemp;
            after2=ntemp->next;
            ntemp->next=after1;
            temp=after1;
            ntemp=after2;
        }
        // assigning random 
        Node* b1=head;
        Node* b2=head->next;
        while(b1){
            if(b1->random) b2->random=b1->random->next;
            b1=b2->next;
            b2=b1->next;
        }
        //breaking again
        b1=head;
        b2=head->next;
        nhead=b2;
        while(b2 && b2->next){
            b1->next=b2->next;
            b1=b1->next;

            b2->next=b1->next;
            b2=b2->next;
        }
        b1->next=NULL;
        return nhead;
    }
};
