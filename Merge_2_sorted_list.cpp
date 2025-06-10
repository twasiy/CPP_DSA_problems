#include<iostream>

class Node{
public:
    int data;
    Node* next;
    Node():next(nullptr){}
};

class List{
public:
    //Helper function to add value in the list
    void push_back(Node*& head,int val){
        Node* newNode = new Node();
        newNode->data = val;
        if(head == nullptr) {
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    //Main task
    Node* mergeTwoLists(Node* list1,Node* list2){
        if(list1 == nullptr || list2 == nullptr){
            return list1 ==nullptr? list2:list1;
        }

        //case1
        if(list1->data <= list2->data){
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }else{
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }
    }

    // Helper function to print the linked list
    void printList(Node* head) {
        Node* temp = head;
        while(temp != nullptr) {
            std::cout << temp->data;
            if(temp->next != nullptr) std::cout << " -> ";
            temp = temp->next;
        }
        std::cout << " -> NULL" << std::endl;
    }

};


int main(){

    //creating first list
    Node* list1{nullptr};
    List ll;
    ll.push_back(list1,1);
    ll.push_back(list1,2);
    ll.push_back(list1,3);
    ll.push_back(list1,4);

    //creating second list
    Node* list2{nullptr};
    ll.push_back(list2,5);
    ll.push_back(list2,6);
    ll.push_back(list2,7);
    ll.push_back(list2,8);
    
    //Main task
    Node* mergelist = ll.mergeTwoLists(list1,list2);
    ll.printList(mergelist);

    return 0;
}