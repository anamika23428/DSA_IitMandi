#include <bits/stdc++.h>
using namespace std;

class Tree {
private:
    vector<int> tree;

public:
    void insert_data(int val) {
        tree.push_back(val);
    }

    int search(int val) {
        for (int i = 0; i < tree.size(); i++) {
            if (val == tree[i]) {
                return i;
            }
        }
        return -1;
    }

    void delete_data(int val) {
        int index = search(val);
        if (index == -1) {
            cout << "Value not found in tree." << endl;
            return;
        }
        tree[index] = tree.back(); // Replace with the last element
        tree.pop_back();           // Remove the last element
    }

    // void inorder(int index = 0) {
    //     if (index >= tree.size()) return;
    //     inorder(2 * index + 1); // Left subtree
    //     cout << tree[index] << " ";
    //     inorder(2 * index + 2); // Right subtree
    // }

    void display() {
        for (int i : tree) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    Tree tree;
    tree.insert_data(10);
    tree.insert_data(20);
    tree.insert_data(30);
    tree.insert_data(40);
    tree.insert_data(50);
    
    tree.display(); // Display initial tree

    cout << "Search 20: " << tree.search(20) << endl;
    
    tree.delete_data(20);
    
    cout << "After deleting 20:" << endl;
    tree.display();

    cout << "Search 20: " << tree.search(20) << endl; // Should return -1

    return 0;
}
