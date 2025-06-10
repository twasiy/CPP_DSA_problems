#include<iostream>
#include<unordered_map>
#include<initializer_list>
#include<vector>

class Node{
public:
    int val;
    Node* next;
    Node* random;
    Node(): val(0), next{nullptr}, random{nullptr} {}
    Node(int v): val(v), next{nullptr}, random{nullptr} {}
};

class List{
    Node* head{nullptr};
public:

    List(std::initializer_list<int> list){
        for(int it:list){
            push_back(it);
        }
    }

    // Constructor for creating list from head pointer
    List(Node* h) : head(h) {}

    //Helper function to add value in the list
    void push_back(int val){
        Node* newNode = new Node();
        newNode->val = val;
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

    // Helper function to set random pointers for testing
    void setRandomPointer(int nodeIndex, int randomIndex) {
        std::vector<Node*> nodes;
        Node* temp = head;
        
        // Collect all nodes
        while(temp != nullptr) {
            nodes.push_back(temp);
            temp = temp->next;
        }
        
        // Set random pointer
        if(nodeIndex < nodes.size() && randomIndex < nodes.size()) {
            nodes[nodeIndex]->random = nodes[randomIndex];
        }
    }

    List copyRandomList() {
        if(head == nullptr){
            return List(nullptr);
        }
        std::unordered_map<Node*, Node*> m;
        
        // First pass: create all nodes and store mapping
        Node* oldtemp = head;
        while(oldtemp != nullptr){
            m[oldtemp] = new Node(oldtemp->val);
            oldtemp = oldtemp->next;
        }
        
        // Second pass: connect next and random pointers
        oldtemp = head;
        while(oldtemp != nullptr){
            if(oldtemp->next != nullptr){
                m[oldtemp]->next = m[oldtemp->next];
            }
            if(oldtemp->random != nullptr){
                m[oldtemp]->random = m[oldtemp->random];
            }
            oldtemp = oldtemp->next;
        }
        
        return List(m[head]);
    }

    List copyRandomList_opt(){
        if (!head) return List(nullptr);

        // Step 1: Insert copy nodes
        Node* temp = head;
        while (temp) {
            Node* node = new Node(temp->val);
            node->next = temp->next;
            temp->next = node;
            temp = node->next;
        }

        // Step 2: Assign random pointers
        temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        // Step 3: Separate the two lists
        temp = head;
        Node* newHead = head->next;
        while (temp) {
            Node* copy = temp->next;
            Node* nxtNode = copy->next;

            temp->next = nxtNode;
            copy->next = nxtNode ? nxtNode->next : nullptr;

            temp = nxtNode;
        }
        return List(newHead);
    }

    // Helper function to print the linked list
    void printList() {
        Node* temp = head;
        std::cout << "List contents:" << std::endl;
        while(temp != nullptr) {
            std::cout << "Node val: " << temp->val;
            if(temp->random != nullptr) {
                std::cout << ", Random points to: " << temp->random->val;
            } else {
                std::cout << ", Random points to: NULL";
            }
            std::cout << std::endl;
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Destructor to prevent memory leaks
    ~List() {
        Node* temp = head;
        while(temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main(){
    List ll{1, 2, 3, 4, 5};
    
    // Set some random pointers for testing
    ll.setRandomPointer(0, 2); // Node 1 points to Node 3
    ll.setRandomPointer(1, 4); // Node 2 points to Node 5
    ll.setRandomPointer(3, 1); // Node 4 points to Node 2
    
    std::cout << "Original list:" << std::endl;
    ll.printList();
    
    // Copy the list and store the result
    List copiedList = ll.copyRandomList();
    
    std::cout << "Copied list:" << std::endl;
    copiedList.printList();
    
    // Test the optimized version too
    List copiedListOpt = ll.copyRandomList_opt();
    
    std::cout << "Copied list (optimized):" << std::endl;
    copiedListOpt.printList();

    return 0;
}