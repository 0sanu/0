#include <iostream>
using namespace std;

struct bstnode {
    int data;
    bstnode* left = NULL;
    bstnode* right = NULL;
};

bstnode* insert(bstnode* temp, int data) {
    if (temp == NULL) {
        temp = new bstnode();
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
    }
    else if (temp->data > data) {
        temp->left = insert(temp->left, data);
    }
    else {
        temp->right = insert(temp->right, data);
    }
    return temp;
}

void search(bstnode* temp, int data) {
    if (temp != NULL) {
        if (temp->data == data) {
            cout << "Data found!" << endl;
            return;
        }
        else if (data < temp->data) {
            search(temp->left, data);
        }
        else {
            search(temp->right, data);
        }
    }
    else {
        cout << "Data not found!" << endl;
    }
}

int depth(bstnode* temp) {
    if (temp == NULL) {
        return 0;
    }
    return (max(depth(temp->left), depth(temp->right)) + 1);
}

int maxval(bstnode* temp) {
    if (temp == NULL) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    while (temp->right != NULL) {
        temp = temp->right;
    }
    cout << "Maximum value is: " << temp->data << endl;
    return temp->data;
}

int minval(bstnode* temp) {
    if (temp == NULL) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    while (temp->left != NULL) {
        temp = temp->left;
    }
    cout << "Minimum value is: " << temp->data << endl;
    return temp->data;
}

void mirror(bstnode* temp) {
    if (temp != NULL) {
        bstnode* a = temp->left;
        temp->left = temp->right;
        temp->right = a;
        mirror(temp->left);
        mirror(temp->right);
    }
}

void inorder(bstnode* temp) {
    if (temp != NULL) {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}

int main() {
    bstnode* root = NULL;
    int ch, n;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Insert a new node" << endl;
        cout << "2. Search for a value" << endl;
        cout << "3. Find maximum value" << endl;
        cout << "4. Find minimum value" << endl;
        cout << "5. Find tree depth" << endl;
        cout << "6. Find mirror" << endl;
        cout << "Enter your choice: ";

        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> n;
                root = insert(root, n);
                cout << "Node inserted" << endl;
                break;

            case 2:
                cout << "Enter the value to search: ";
                cin >> n;
                search(root, n);
                break;

            case 3:
                maxval(root);
                break;

            case 4:
                minval(root);
                break;

            case 5:
                cout << "Tree depth is: " << depth(root) << endl;
                break;

            case 6:
                cout << "Mirror (inorder traversal of mirrored tree):" << endl;
                mirror(root);
                inorder(root);
                cout << endl;
                break;

            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    }

    return 0;
}