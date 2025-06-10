#include <iostream>

struct Node{
    int data;
    Node* next;
};

class List{
    Node* head{nullptr};
    Node* tail{nullptr};

public:
    void insert_in_front(int val){
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        if(head == nullptr){
            head = tail = newNode;
        }else {
            head = newNode;
        }
    }

    void insert_in_back(int val){
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

    void printll(){
        Node* temp = head;
        while(temp != nullptr){
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << '\n';
    }


    int middleNode(){
        int count{};
        if (head == nullptr) {
            std::cout << "List is empty!" << std::endl;
        }
        Node* temp = head;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        int index = (count/2);
        Node* temp1 = head;
        for(int i{};i<index;i++){
            temp1 = temp1->next;
        }
        return temp1->data;
    }

    int middle_Node(){
        Node* slow;
        Node* fast;
        slow = fast = head;

        if (head == nullptr) {
            std::cout << "List is empty!" << std::endl;
        }

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};

int main(){

    List list;

    list.insert_in_front(5);
    list.insert_in_front(6);
    list.insert_in_front(4);
    list.insert_in_front(8);
    list.insert_in_back(7);
    list.insert_in_back(1);
    list.insert_in_back(3);

    // list.printll();

    // int middle = list.middleNode();
    // std::cout << middle << std::endl;

    int middle = list.middle_Node();
    std::cout << middle << std::endl;


    return 0;
}