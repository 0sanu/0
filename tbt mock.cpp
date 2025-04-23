#include <iostream>
using namespace std;

struct Node {
    Node *left, *right;
    int data;
    int lthread, rthread;
};

class TBST {
public:
    Node* insert(Node* root, int key);
    void inorder(Node* root);
    Node* inorderSuccessor(Node* ptr);
    Node* deleteLeaf(Node* root, int key);
};

Node* TBST::insert(Node* root, int key) {
    Node* ptr = root;
    Node* parent = NULL;

    while (ptr != NULL) {
        parent = ptr;
        if (key < ptr->data) {
            if (ptr->lthread == 1)
                ptr = ptr->left;
            else break;
        } else {
            if (ptr->rthread == 1)
                ptr = ptr->right;
            else break;
        }
    }

    Node* temp = new Node;
    temp->data = key;
    temp->lthread = 0;
    temp->rthread = 0;

    if (parent == NULL) {
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
    } else if (key < parent->data) {
        temp->left = parent->left;
        temp->right = parent;
        parent->lthread = 1;
        parent->left = temp;
    } else {
        temp->left = parent;
        temp->right = parent->right;
        parent->rthread = 1;
        parent->right = temp;
    }

    return root;
}

Node* TBST::inorderSuccessor(Node* ptr) {
    if (ptr->rthread == 0)
        return ptr->right;
    ptr = ptr->right;
    while (ptr->lthread == 1)
        ptr = ptr->left;
    return ptr;
}

void TBST::inorder(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty\n";
        return;
    }
    Node* ptr = root;
    while (ptr->lthread == 1)
        ptr = ptr->left;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = inorderSuccessor(ptr);
    }
    cout << endl;
}

Node* TBST::deleteLeaf(Node* root, int key) {
    Node* ptr = root;
    Node* parent = NULL;

    while (ptr != NULL) {
        if (key == ptr->data)
            break;
        parent = ptr;
        if (key < ptr->data) {
            if (ptr->lthread == 1)
                ptr = ptr->left;
            else
                ptr = NULL;
        } else {
            if (ptr->rthread == 1)
                ptr = ptr->right;
            else
                ptr = NULL;
        }
    }

    if (ptr == NULL)
        return root;

    if (ptr->lthread == 0 && ptr->rthread == 0) {
        if (parent == NULL) {
            delete ptr;
            root = NULL;
        } else if (ptr == parent->left) {
            parent->lthread = 0;
            parent->left = ptr->left;
            delete ptr;
        } else {
            parent->rthread = 0;
            parent->right = ptr->right;
            delete ptr;
        }
    }

    return root;
}

// Main function
int main() {
    TBST t;
    Node* root = NULL;
    int key, choice;

    while (1) {
        cout << "\n1. Insert\n2. Delete Leaf Node\n3. Display Inorder\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> key;
                root = t.insert(root, key);
                break;
            case 2:
                cout << "Enter leaf node to delete: ";
                cin >> key;
                root = t.deleteLeaf(root, key);
                break;
            case 3:
                t.inorder(root);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}