/*Implementation of a direct access file -Insertion and deletion of a record from a direct access file*/

#include <iostream>
#include <fstream>
using namespace std;

const char FILENAME[] = "data.dat";
const int MAX_NAME = 20;

struct Record {
    int id;
    char name[MAX_NAME];
    bool deleted;

    Record(int i = -1, const char* n = "", bool d = false);
};

class DirectFile {
public:
    void insert(int index, const char* name);
    void remove(int index);
    void show();
};

// Record constructor (without cstring)
Record::Record(int i, const char* n, bool d) {
    id = i;
    int j = 0;
    while (j < MAX_NAME - 1 && n[j] != '\0') {
        name[j] = n[j];
        j++;
    }
    name[j] = '\0';
    deleted = d;
}

// Insert record at index
void DirectFile::insert(int index, const char* name) {
    fstream file(FILENAME, ios::in | ios::out | ios::binary);
    if (!file) {
        file.open(FILENAME, ios::out | ios::binary);
        file.close();
        file.open(FILENAME, ios::in | ios::out | ios::binary);
    }

    Record r(index, name, false);
    file.seekp(index * sizeof(Record), ios::beg);
    file.write((char*)&r, sizeof(r));
    file.close();

    cout << "Inserted at index " << index << ".\n";
}

// Delete (mark as deleted)
void DirectFile::remove(int index) {
    fstream file(FILENAME, ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "File not found.\n";
        return;
    }

    file.seekg(index * sizeof(Record), ios::beg);
    Record r;
    file.read((char*)&r, sizeof(r));

    if (file.gcount() == 0 || r.deleted) {
        cout << "No record or already deleted.\n";
    } else {
        r.deleted = true;
        file.seekp(index * sizeof(Record), ios::beg);
        file.write((char*)&r, sizeof(r));
        cout << "Deleted at index " << index << ".\n";
    }

    file.close();
}

// Show all records
void DirectFile::show() {
    ifstream file(FILENAME, ios::binary);
    if (!file) {
        cout << "No records found.\n";
        return;
    }

    Record r;
    int i = 0;
    while (file.read((char*)&r, sizeof(r))) {
        if (!r.deleted) {
            cout << "Index: " << i << ", ID: " << r.id << ", Name: " << r.name << "\n";
        }
        i++;
    }

    file.close();
}

// Main menu
int main() {
    DirectFile df;
    int choice, index;
    char name[MAX_NAME];

    do {
        cout << "\n1. Insert\n2. Delete\n3. Show\n4. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter index: ";
            cin >> index;
            cin.ignore();
            cout << "Enter name: ";
            cin.getline(name, MAX_NAME);
            df.insert(index, name);
        } else if (choice == 2) {
            cout << "Enter index to delete: ";
            cin >> index;
            df.remove(index);
        } else if (choice == 3) {
            df.show();
        }
    } while (choice != 4);

    return 0;
}
