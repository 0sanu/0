/*Company maintains employee information as employee ID, name,
designation and salary. Allow user to add, delete information of employee. Display
information of particular employee. If employee does not exist an appropriate message is
displayed. If it is, then the system displays the employee details. Use index sequential file to
maintain the data.*/ 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Employee {
    int id;
    char name[20];
    char designation[20];
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

    while (data >> e.id >> e.name >> e.designation >> e.salary) {
        index << e.id << " " << pos << endl;
        pos = data.tellg(); 
    }

    data.close();
    index.close();
}

void addEmployee(string dataFile, string indexFile) {
    Employee newEmp, temp;
    cout << "Enter Employee ID: ";
    cin >> newEmp.id;
    cout << "Enter Name: ";
    cin >> newEmp.name;
    cout << "Enter Designation: ";
    cin >> newEmp.designation;
    cout << "Enter Salary: ";
    cin >> newEmp.salary;

    ifstream infile(dataFile);
    ofstream outfile("temp.txt");

    bool inserted = false;
    int pos = 0;

    while (infile >> temp.id >> temp.name >> temp.designation >> temp.salary) {
        if (!inserted && newEmp.id < temp.id) {
            outfile << newEmp.id << " " << newEmp.name << " " << newEmp.designation << " " << newEmp.salary << endl;
            inserted = true;
        }
        outfile << temp.id << " " << temp.name << " " << temp.designation << " " << temp.salary << endl;
    }

    if (!inserted) {
        outfile << newEmp.id << " " << newEmp.name << " " << newEmp.designation << " " << newEmp.salary << endl;
    }

    infile.close();
    outfile.close();

    remove(dataFile.c_str());
    rename("temp.txt", dataFile.c_str());

    updateIndex(indexFile, dataFile);

    cout << "Employee added successfully!\n";
}

void displayEmployees(string dataFile) {
    ifstream file(dataFile);
    Employee e;
    
    cout << "\n--- Employee List (Sorted by ID) ---\n";
    while (file >> e.id >> e.name >> e.designation >> e.salary) {
        cout << "ID: " << e.id << ", Name: " << e.name
             << ", Designation: " << e.designation
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
        dataFileIn >> e.id >> e.name >> e.designation >> e.salary;
        cout << "\nEmployee Found:\n";
        cout << "ID: " << e.id << ", Name: " << e.name
             << ", Designation: " << e.designation
             << ", Salary: " << e.salary << endl;
    } else {
        cout << "Employee with ID " << emp_id << " not found.\n";
    }

    dataFileIn.close();
}

void deleteEmployee(string dataFile, string indexFile, int emp_id) {
    ifstream infile(dataFile);
    ofstream outfile("temp.txt");
    Employee e;
    bool found = false;

    while (infile >> e.id >> e.name >> e.designation >> e.salary) {
        if (e.id == emp_id) {
            found = true; 
            continue;
        }
        outfile << e.id << " " << e.name << " " << e.designation << " " << e.salary << endl;
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
