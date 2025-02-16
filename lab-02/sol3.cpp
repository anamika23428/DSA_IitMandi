#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() { head = nullptr; }

    void insert_at_head(int data) {
        Node* node = new Node(data);
        if (head == nullptr) {
            node->next = node;
            head = node;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = node;
        node->next = head;
        head = node;
    }

    void insert_at_tail(int data) {
        Node* node = new Node(data);
        if (head == nullptr) {
            node->next = node;
            head = node;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = node;
        node->next = head;
    }

    void insert_at_kth(int data, int k) {
        if (k <= 1) {  // Insert at head if k is 1 or invalid
            insert_at_head(data);
            return;
        }

        Node* temp = head;
        int i = 1;

        while (temp->next != head && i < k - 1) {
            temp = temp->next;
            i++;
        }

        if (temp->next == head) {
            insert_at_tail(data);
            return;
        }

        Node* node = new Node(data);
        node->next = temp->next;
        temp->next = node;
    }

    // Delete from head
    void delete_from_head() {
        if (head == nullptr) return;  // Empty list

        Node* temp = head;
        if (head->next == head) {  // Only one node
            delete head;
            head = nullptr;
            return;
        }

        while (temp->next != head) {  
            temp = temp->next;  // Reach the last node
        }
        
        Node* toDelete = head;
        head = head->next;
        temp->next = head;  // Update last node to new head
        delete toDelete;
    }

    // Delete from tail
    void delete_from_tail() {
        if (head == nullptr) return;

        Node* temp = head;
        if (head->next == head) {  // Only one node
            delete head;
            head = nullptr;
            return;
        }

        while (temp->next->next != head) {  
            temp = temp->next;  // Reach second-last node
        }

        Node* toDelete = temp->next;
        temp->next = head;  // Update tail to new last node
        delete toDelete;
    }

    // Delete at kth position
    void delete_at_kth(int k) {
        if (head == nullptr || k <= 1) {  
            delete_from_head();  // Delete head if k is 1 or invalid
            return;
        }

        Node* temp = head;
        int i = 1;

        while (temp->next != head && i < k - 1) {
            temp = temp->next;
            i++;
        }

        if (temp->next == head) return;  // k exceeds list size

        Node* toDelete = temp->next;
        temp->next = toDelete->next;

        delete toDelete;
    }

    void print() {
        if (head == nullptr) return;
        Node* temp = head;
        
            cout << temp->data << " -> ";
            temp = temp->next;
        while (temp != head){
            cout << temp->data << " -> ";
            temp = temp->next;}
        cout << "(head)" << endl;
    }
    
};

int main() {
    CircularLinkedList cll;
    cll.insert_at_tail(1);
    cll.insert_at_tail(2);
    cll.insert_at_tail(3);
    cll.insert_at_tail(4);
    cll.insert_at_tail(5);
    
    cout << "Initial List: ";
    cll.print();

    cll.delete_from_head();
    cout << "After deleting head: ";
    cll.print();

    cll.delete_from_tail();
    cout << "After deleting tail: ";
    cll.print();

    cll.delete_at_kth(2);
    cout << "After deleting 2nd position: ";
    cll.print();

    return 0;
}
