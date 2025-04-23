#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* child;
    Node* sibling;

    Node(string name) {
        data = name;
        child = nullptr;
        sibling = nullptr;
    }
};

class Book {
    Node* root;

    void displayNode(Node* node, int level) {
        while (node) {
            for (int i = 0; i < level; i++) cout << "  ";
            cout << node->data << "\n";
            if (node->child)
                displayNode(node->child, level + 1);
            node = node->sibling;
        }
    }

public:
    Book() {
        root = nullptr;
    }

    void addBook() {
        if (root) {
            cout << "Book already exists.\n";
            return;
        }
        string name;
        cout << "Enter book name: ";
        cin.ignore();
        getline(cin, name);
        root = new Node(name);
        cout << "Book added.\n";
    }

    void addChapter() {
        if (!root) {
            cout << "Add a book first.\n";
            return;
        }
        string name;
        cout << "Enter chapter name: ";
        cin.ignore();
        getline(cin, name);
        Node* newChapter = new Node(name);
        if (!root->child)
            root->child = newChapter;
        else {
            Node* temp = root->child;
            while (temp->sibling)
                temp = temp->sibling;
            temp->sibling = newChapter;
        }
        cout << "Chapter added.\n";
    }

    void addSection() {
        if (!root || !root->child) {
            cout << "Add chapters first.\n";
            return;
        }
        string chapterName, sectionName;
        cout << "Enter chapter name to add section: ";
        cin.ignore();
        getline(cin, chapterName);
        Node* chapter = root->child;
        while (chapter && chapter->data != chapterName)
            chapter = chapter->sibling;
        if (!chapter) {
            cout << "Chapter not found.\n";
            return;
        }
        cout << "Enter section name: ";
        getline(cin, sectionName);
        Node* newSection = new Node(sectionName);
        if (!chapter->child)
            chapter->child = newSection;
        else {
            Node* temp = chapter->child;
            while (temp->sibling)
                temp = temp->sibling;
            temp->sibling = newSection;
        }
        cout << "Section added.\n";
    }

    void display() {
        if (!root) {
            cout << "No book exists.\n";
            return;
        }
        cout << "\nBook Structure:\n";
        displayNode(root, 0);
    }
};

int main() {
    Book book;
    int choice;

    do {
        cout << "\n---- MENU ----\n";
        cout << "1. Add Book\n";
        cout << "2. Add Chapter\n";
        cout << "3. Add Section\n";
        cout << "4. Display Book Structure\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: book.addBook(); break;
            case 2: book.addChapter(); break;
            case 3: book.addSection(); break;
            case 4: book.display(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}