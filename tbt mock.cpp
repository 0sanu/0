#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    bool lthread; // true if left pointer is a thread
    bool rthread; // true if right pointer is a thread
};

class TBST {
public:
    Node* insert(Node* root, int key);
    void inorder(Node* root);
    Node* deleteLeaf(Node* root, int key);

private:
    Node* inorderSuccessor(Node* ptr);
};

// Insert a node into TBST
Node* TBST::insert(Node* root, int key) {
    Node* curr = root;
    Node* parent = nullptr;

    while (curr != nullptr) {
        if (key == curr->data) {
            cout << "Duplicate key not allowed.\n";
            return root;
        }
        parent = curr;
        if (key < curr->data) {
            if (curr->lthread)
                curr = curr->left;
            else
                break;
        } else {
            if (curr->rthread)
                curr = curr->right;
            else
                break;
        }
    }

    Node* newNode = new Node{key, nullptr, nullptr, false, false};

    if (parent == nullptr) {
        // If root is null, the first node is inserted as root
        root = newNode;
    } else if (key < parent->data) {
        newNode->left = parent->left;
        newNode->right = parent;
        parent->lthread = true;
        parent->left = newNode;
    } else {
        newNode->left = parent;
        newNode->right = parent->right;
        parent->rthread = true;
        parent->right = newNode;
    }

    cout << "Node inserted successfully\n";
    return root;
}

// Inorder Successor
Node* TBST::inorderSuccessor(Node* node) {
    if (!node->rthread)
        return node->right;

    node = node->right;
    while (node->lthread)
        node = node->left;
    return node;
}

// Inorder Traversal
void TBST::inorder(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }

    Node* curr = root;
    while (curr->lthread)
        curr = curr->left;

    cout << "Inorder Traversal: ";
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = inorderSuccessor(curr);
    }
    cout << endl;
}

// Delete a leaf node
Node* TBST::deleteLeaf(Node* root, int key) {
    Node* curr = root;
    Node* parent = nullptr;

    while (curr != nullptr) {
        if (key == curr->data)
            break;
        parent = curr;
        if (key < curr->data) {
            if (curr->lthread)
                curr = curr->left;
            else
                curr = nullptr;
        } else {
            if (curr->rthread)
                curr = curr->right;
            else
                curr = nullptr;
        }
    }

    if (curr == nullptr) {
        cout << "Key not found.\n";
        return root;
    }

    if (!curr->lthread && !curr->rthread) {
        if (parent == nullptr) {
            delete curr;
            return nullptr;
        } else if (parent->left == curr) {
            parent->lthread = false;
            parent->left = curr->left;
        } else {
            parent->rthread = false;
            parent->right = curr->right;
        }
        delete curr;
        cout << "Node deleted successfully\n";
    } else {
        cout << "Only leaf nodes can be deleted.\n";
    }

    return root;
}

// Main
int main() {
    TBST tree;
    Node* root = nullptr;
    int choice, key;

    while (true) {
        cout << "\n1. Insert\n2. Inorder\n3. Delete Leaf Node\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> key;
                root = tree.insert(root, key);
                break;
            case 2:
                tree.inorder(root);
                break;
            case 3:
                cout << "Enter leaf node to delete: ";
                cin >> key;
                root = tree.deleteLeaf(root, key);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
