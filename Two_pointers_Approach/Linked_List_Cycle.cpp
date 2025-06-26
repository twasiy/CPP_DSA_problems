#include <iostream>
#include <initializer_list>

struct Node{
    int data;
    Node* next;
};

class List{
    Node* head;
    Node* tail;
public:
    List(std::initializer_list<int> list):head(nullptr),tail(nullptr){
        for(int val:list){
            push_back(val);
        }
    }
    List():head(nullptr),tail(nullptr){};

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
        if (cycleNode) temp->next = cycleNode; // Last node points to cycleNode
    }

    //The main problem statement
    bool hascycle(){
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast){
                return true;
            }
        }
        return false;
    }
};

int main(){
    List ll{1,2,3,4,5,6,7,8,9};

    ll.create_cycle(5);
    std::cout << ll.hascycle() << std::endl;

    return 0;
}
