#include<iostream>

struct Node{
    int data;
    Node* next;
};

class List{
    Node* head{nullptr};
    Node* tail{nullptr};
public:
    void push_front(int val){
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;

        if(head == nullptr){
            head = tail = newNode;
        }else{
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;

        if(head == nullptr){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Creates a cycle at the given position (1-based index)
    void create_cycle(int pos) {
        if (pos <= 0) return;

        Node* temp = head;
        Node* cycleNode = nullptr;
        int count = 1;

        while (temp && temp->next) {
            if (count == pos) cycleNode = temp;
            temp = temp->next;
            count++;
        }

        if (cycleNode)
            temp->next = cycleNode; // Last node points to cycleNode
    }

    bool hascycle(){
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                return true;
            }
        }
        return false;
    }

    Node* detect_cycle(){
        Node* slow = head;
        Node* fast = head;
        bool iscycle = false;

        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                iscycle = true;
                break;
            }
        }
        if(!iscycle) return NULL;

        slow = head;
        Node* prev = nullptr; //initializing
        while(slow != fast){
            slow = slow->next;
            prev = fast; //for removing 
            fast = fast->next;
        }
        prev->next = nullptr;//remove the cycle

        return slow;
    }


    void printll(){
        Node* temp = head;
        while(temp != nullptr){
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << '\n';
    }
};


int main(){
    List ll;

    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    // ll.printll();

    ll.create_cycle(5);

    bool state = ll.hascycle();

    std::cout << state << std::endl;


    return 0;
}