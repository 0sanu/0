#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Employee {
    int id;
    char name[20];
    int salary;
};

struct Index {
    int id;
    int position;
};

void updateIndex(string indexFile, string dataFile) {
    ifstream data(dataFile);
    ofstream index(indexFile);
    Employee e;
    int pos = 0;

    while (data >> e.id >> e.name >> e.salary) {
        index << e.id << " " << pos << endl;
        pos = data.tellg();
    }
    data.close();
    index.close();
}

void addEmployee(string dataFile, string indexFile) {
    Employee newEmp;
    cout << "Enter Employee ID: ";
    cin >> newEmp.id;
    cout << "Enter Name: ";
    cin >> newEmp.name;
    cout << "Enter Salary: ";
    cin >> newEmp.salary;

    ofstream outfile(dataFile, ios::app);
    outfile << newEmp.id << " " << newEmp.name << " " << newEmp.salary << endl;
    outfile.close();

    updateIndex(indexFile, dataFile);
    cout << "Employee added successfully!\n";
}

void displayEmployees(string dataFile) {
    ifstream file(dataFile);
    Employee e;
    cout << "\n--- Employee List ---\n";
    while (file >> e.id >> e.name >> e.salary) {
        cout << "ID: " << e.id << ", Name: " << e.name
             << ", Salary: " << e.salary << endl;
    }
    file.close();
}

void searchEmployee(string dataFile, string indexFile, int emp_id) {
    ifstream indexFileIn(indexFile);
    ifstream dataFileIn(dataFile);
    Index idx;
    bool found = false;
    int position = -1;

    while (indexFileIn >> idx.id >> idx.position) {
        if (idx.id == emp_id) {
            position = idx.position;
            found = true;
            break;
        }
    }
    indexFileIn.close();

    if (found) {
        dataFileIn.seekg(position);
        Employee e;
        dataFileIn >> e.id >> e.name >> e.salary;
        cout << "\nEmployee Found:\n";
        cout << "ID: " << e.id << ", Name: " << e.name
             << ", Salary: " << e.salary << endl;
    } else {
        cout << "Employee not found.\n";
    }
    dataFileIn.close();
}

void deleteEmployee(string dataFile, string indexFile, int emp_id) {
    ifstream infile(dataFile);
    ofstream outfile("temp.txt");
    Employee e;
    bool found = false;

    while (infile >> e.id >> e.name >> e.salary) {
        if (e.id == emp_id) {
            found = true; 
            continue;
        }
        outfile << e.id << " " << e.name << " " << e.salary << endl;
    }
    infile.close();
    outfile.close();

    if (found) {
        remove(dataFile.c_str());
        rename("temp.txt", dataFile.c_str());
        updateIndex(indexFile, dataFile);
        cout << "Employee deleted successfully!\n";
    } else {
        cout << "Employee not found!\n";
    }
}

int main() {
    string dataFile = "employees.txt";
    string indexFile = "index.txt";

    ofstream f1(dataFile, ios::trunc);
    ofstream f2(indexFile, ios::trunc);
    f1.close();
    f2.close();

    int choice;
    do {
        cout << "\n1. Add Employee\n2. Display Employees\n3. Search Employee\n4. Delete Employee\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            addEmployee(dataFile, indexFile);
        } else if (choice == 2) {
            displayEmployees(dataFile);
        } else if (choice == 3) {
            int emp_id;
            cout << "Enter Employee ID to search: ";
            cin >> emp_id;
            searchEmployee(dataFile, indexFile, emp_id);
        } else if (choice == 4) {
            int emp_id;
            cout << "Enter Employee ID to delete: ";
            cin >> emp_id;
            deleteEmployee(dataFile, indexFile, emp_id);
        }

    } while (choice != 5);

    return 0;
}