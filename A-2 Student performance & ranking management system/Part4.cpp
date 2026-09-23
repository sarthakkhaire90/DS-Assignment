#include <iostream>
using namespace std;

int main() {
    int rollNo[25];
    int marks[98];
    int n = 0;
    int choice;
    int searchRoll;

    do {
        cout << "\n\n-----STUDENT MANAGEMENT SYSTEM-----";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nEnter Roll Number: ";
            cin >> rollNo[n];

            cout << "Enter Marks: ";
            cin >> marks[n];

            n++;

            cout << "Student Added!";
        }

        else if (choice == 2) {
            cout << "\n-----STUDENT RECORDS-----\n";

            for (int i = 0; i < n; i++) {
                cout << "Roll Number: " << rollNo[i];
                cout << "  Marks: " << marks[i] << endl;
            }
        }

        else if (choice == 3) {
            cout << "\nEnter Roll Number to search: ";
            cin >> searchRoll;

            bool found = false;

            for (int i = 0; i < n; i++) {
                if (rollNo[i] == searchRoll) {
                    cout << "\nStudent Found!";
                    cout << "\nRoll Number: " << rollNo[i];
                    cout << "\nMarks: " << marks[i];

                    found = true;
                }
            }

            if (!found) {
                cout << "\nStudent Not Found!";
            }
        }

        else if (choice == 4) {
            cout << "\nThank you!";
        }

        else {
            cout << "\nInvalid Choice!";
        }

    } while (choice != 4);

    return 0;
}
