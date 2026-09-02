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
        map<Node*,Node*>m;
        while(temp){
            m[temp]=ntemp;
            temp=temp->next;
            ntemp=ntemp->next;
        }

        for(auto i:m){
            m[i.first]->random=m[i.first->random];
        }
        return nhead;
    }
};
