class ListNode{
    public:
        int val;
        int key;
        ListNode* next;
        ListNode* prev;
    ListNode(int key,int val){
        this->key=key;
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
class LRUCache {
public:
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    ListNode* head=NULL;
    ListNode* temp=NULL;
    map<int,ListNode*> m;
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        else if(m[key]==head) return m[key]->val;
        else if(m[key]==temp){
            m[key]->prev->next=NULL;
            temp=m[key]->prev;
            m[key]->prev=NULL;
            head->prev=m[key];
            m[key]->next=head;
            head=m[key];
            return m[key]->val;
        }
        else{
            m[key]->prev->next=m[key]->next;
            m[key]->next->prev=m[key]->prev;
            m[key]->prev=NULL;
            m[key]->next=head;
            head->prev=m[key];
            head=m[key];
            return m[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        ListNode* c=new ListNode(key,value);
        c->next=head;
        if(head) head->prev=c;
        if(temp==NULL) temp=c;
        head=c;
        m[key]=c;
        if(m.size()>cap) {
            m.erase(temp->key);
            if(temp->prev) temp=temp->prev;
            temp->next=NULL;
        }
    }
};
