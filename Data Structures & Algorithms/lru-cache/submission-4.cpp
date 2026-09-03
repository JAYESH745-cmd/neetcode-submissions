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

    // If key already exists
    if (m.find(key) != m.end()) {

        ListNode* node = m[key];
        node->val = value;

        // Already MRU
        if (node == head)
            return;

        // Remove node from current position
        if (node->prev)
            node->prev->next = node->next;

        if (node->next)
            node->next->prev = node->prev;

        // If it was LRU, update temp
        if (node == temp)
            temp = node->prev;

        // Move node to front
        node->prev = NULL;
        node->next = head;
        head->prev = node;
        head = node;

        return;
    }

    // New key
    ListNode* c = new ListNode(key, value);

    c->next = head;

    if (head)
        head->prev = c;

    head = c;

    // First node
    if (temp == NULL)
        temp = c;

    m[key] = c;

    // Capacity exceeded
    if (m.size() > cap) {

        ListNode* old = temp;

        temp = temp->prev;

        if (temp)
            temp->next = NULL;

        m.erase(old->key);

        delete old;
    }
}
};
