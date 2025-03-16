#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data; 
    Node* next;

    Node(char val) {  
        data = val;
        next = nullptr;
    }
};

struct Stack {
    Node* top;
    Stack() { top = nullptr; }

    bool isempty() { return top == nullptr; }

    void push(char val) {  
        Node* node = new Node(val);
        node->next = top;
        top = node;
    }

    char pop() {
        if (isempty()) {
            cout << "Stack is empty" << endl;
            return '\0'; 
        }
        Node* temp = top;
        char val = top->data;
        top = top->next;
        delete temp;
        return val;
    }
};

bool isBalanced(string s) {
    Stack st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == '}' || c == ']') {  
            if (st.isempty()) return false;

            char t = st.pop();
            if ((t == '(' && c != ')') || (t == '{' && c != '}') || (t == '[' && c != ']')) {
                return false;
            }
        }
    }
    return st.isempty();
}

int main() {
    string s;
    cin >> s;

    if (isBalanced(s)) cout << "true";
    else cout << "false";

    return 0;
}
