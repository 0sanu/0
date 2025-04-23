#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct student {
    int roll;
    string name;
    string divi;
    string add;
};

void addStudent () {
    ofstream outFile ("StudentInfo.txt", ios::app);
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }
    student newstudent;
    cout << "\nEnter roll no.: ";
    cin >> newstudent.roll;
    cout << "\nEnter name: ";
    cin.ignore();
    getline (cin, newstudent.name);
    cout << "\nEnter division: ";
    getline (cin, newstudent.divi);
    cout << "\nEnter address: ";
    getline (cin, newstudent.add);
    
    outFile << newstudent.roll << " " << newstudent.name << " " << newstudent.divi << " " << newstudent.add << endl;
    cout << "\nStudent Information added successfully!";
    
    outFile.close();
}

void deleteStudent () {
    ifstream inFile ("StudentInfo.txt");
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return;
    }
    
    ofstream tempFile ("temp.txt");
    if (!tempFile) {
        cerr << "Error opening temp file." << endl;
        inFile.close();
        return;
    }
    
    int roll_no;
    cout << "\nEnter roll no. to delete: ";
    cin >> roll_no;
    
    bool found = false;
    student ostudent;
    
    while (inFile >> ostudent.roll >> ostudent.name >> ostudent.divi >> ostudent.add) {
        if (ostudent.roll != roll_no) {
            tempFile << ostudent.roll << " " << ostudent.name << " " << ostudent.divi << " " << ostudent.add << endl;
        }
        else {
            found = true;
        }
    }
    
    inFile.close();
    tempFile.close();
    
    remove ("StudentInfo.txt");
    rename ("temp.txt", "StudentInfo.txt");
    
    if (found) {
        cout << "Student data deleted successfully!" << endl;
    }
    else {
        cout << "Student with roll no. " << roll_no << " not found." << endl;
    }
}

void display () {
    ifstream inFile ("StudentInfo.txt");
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return;
    }
    
    int roll_no;
    cout << "\nEnter roll no. to display: ";
    cin >> roll_no;
    
    student ostudent;
    bool found = false;
    
    while (inFile >> ostudent.roll >> ostudent.name >> ostudent.divi >> ostudent.add) {
        if (ostudent.roll == roll_no) {
            found = true;
            cout << "Student Information:" << endl;
            cout << "Roll no.: " << ostudent.roll << endl;
            cout << "Name: " << ostudent.name << endl;
            cout << "Division: " << ostudent.divi << endl;
            cout << "Address: " << ostudent.add << endl;
            break;
        }
    }
    if (!found) {
        cout << "Student not found." << endl;
    }
    inFile.close();
}

int main () {
    int choice;
    
    while (choice != 4) {
        cout << "\n****Menu****" << endl;
        cout << "1. Add Student." << endl;
        cout << "2. Delete Student." << endl;
        cout << "3. Display Student." << endl;
        cout << "4. Exit." << endl;
        
        cout << "\nEnter choice: ";
        cin >> choice;
        
        student ostudent;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }
    return 0;
}
