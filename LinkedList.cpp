// Easy
// 707. Design Linked List
class MyLinkedList {
public:
    struct ListNode{
        int val;
        struct ListNode* next;
    };
    struct ListNode* head;
    struct ListNode* current;
    struct ListNode* prev;
    struct ListNode* tail;
    int size;
    /** Initialize your data structure here. */
    MyLinkedList() {
        head= NULL;
        current= NULL;
        prev = NULL;
        tail= NULL;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        
        if (index >= size || index < 0)
            return -1;
        
        current = head;
        for (int i = 0; i < index; i++ )
        {
            current = current->next;
        }
        return current->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) { 
        struct ListNode* newnode = new ListNode;
        newnode->val = val;
        newnode->next = head;
        head = newnode;
        
        if(size==0)
            tail = newnode;
        
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        
        struct ListNode* newnode = new ListNode();
        newnode->val = val;
        newnode->next = NULL;
        if (size == 0)
        {
            head = newnode;
            tail = newnode;
        }
        else 
            tail->next = newnode;
        
        tail = newnode;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size || index < 0)
            return;
        prev = head;
        if (index!=0 && index<size)
        {
            for (int i = 0; i < index - 1; i++ )
            {
                prev = prev->next;
            }
            current = prev->next;
            struct ListNode* newnode = new ListNode();
            newnode->val = val;
            newnode->next = current;
            prev->next=newnode;
        }
        else if (index == 0)
        {
            struct ListNode* newnode = new ListNode();
            newnode->val = val;
            newnode->next = head;
            head = newnode;
        }
        else if (index == size)
        {
            struct ListNode* newnode = new ListNode();
            newnode->val = val;
            newnode->next = NULL;
            this->tail->next = newnode;
            tail = newnode;
        }
        
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= size || index < 0 || size<1)
            return;
        prev = head;
        current = head;
        if (index!=0 && index<size)
        {
            for (int i = 0; i < index - 1; i++ )
            {
                prev = prev->next;
            }
            current = prev->next;
            prev->next = current->next;
            delete current;
            
            if (index == size-1)
                tail = prev;
        }
        else if (index == 0)
        {
            head = current->next;
            delete current;
        }
        
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
