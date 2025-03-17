#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) { data = val; next = nullptr; }
};

class Ll {
private:
    Node* head;

public:
    Ll() { head = nullptr; }  // Corrected constructor

    void push(int new_data) {
        Node* node = new Node(new_data);
        if (head == nullptr) { head = node; return; }
        Node* temp = head;
        while (temp->next) { temp = temp->next; }
        temp->next = node;
    }

    void fun() {
        vector<Node*> ptr;
        vector<int> div;
        Node* temp = head;
        int cnt = 1;

        while (temp) {
          
            for (size_t i = 0; i < div.size(); i++) {
                if (cnt % div[i] == 0 && ptr[i] != nullptr) {
                    ptr[i] = ptr[i]->next;
                }
            }

            
            if (cnt == 1) {
                ptr.push_back(head);
                div.push_back(2);
            } 
            else if (cnt % (div.back()+1)==0) { 
                ptr.push_back(head);
                div.push_back(div.back() + 1); 
            }

            cnt++;
            temp = temp->next;
        }

        // Print results
        cout << "Fractional elements:" << endl;
        for (size_t i = 0; i < ptr.size(); i++) {
            if (ptr[i]) {
                cout << "Element at n/" << div[i] << " : " << ptr[i]->data << endl;
            }
        }
    }
};

int main() {
    Ll ll;
    int val;

    cout << "Enter values (-1 to stop): ";
    while (cin >> val && val != -1) {
        ll.push(val);
    }

    ll.fun();

    return 0;
}
