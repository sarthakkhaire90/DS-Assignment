#include <iostream>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    string disease;
    Patient* next;
};

const int SIZE = 10;
Patient* hashTable[SIZE] = {NULL};

int hashFunction(int id) {
    return id % SIZE;
}

void registerPatient() {
    Patient* newPatient = new Patient;

    cout << "Enter Patient ID: ";
    cin >> newPatient->id;

    int index = hashFunction(newPatient->id);
    Patient* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->id == newPatient->id) {
            cout << "Patient ID already exists!\n";
            delete newPatient;
            return;
        }
        temp = temp->next;
    }

    cout << "Enter Patient Name: ";
    cin.ignore();
    getline(cin, newPatient->name);

    cout << "Enter Age: ";
    cin >> newPatient->age;

    cout << "Enter Disease: ";
    cin.ignore();
    getline(cin, newPatient->disease);

    newPatient->next = hashTable[index];
    hashTable[index] = newPatient;

    cout << "Patient registered successfully!\n";
}

// Update Patient
void updatePatient() {
    int id;

    cout << "Enter Patient ID: ";
    cin >> id;

    int index = hashFunction(id);
    Patient* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, temp->name);

            cout << "Enter New Age: ";
            cin >> temp->age;

            cout << "Enter New Disease: ";
            cin.ignore();
            getline(cin, temp->disease);

            cout << "Patient information updated!\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Patient not found!\n";
}

void dischargePatient() {
    int id;

    cout << "Enter Patient ID: ";
    cin >> id;

    int index = hashFunction(id);

    Patient* temp = hashTable[index];
    Patient* prev = NULL;

    while (temp != NULL) {
        if (temp->id == id) {
            if (prev == NULL) {
                hashTable[index] = temp->next;
            } else {
                prev->next = temp->next;
            }

            delete temp;
            cout << "Patient discharged successfully!\n";
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Patient not found!\n";
}

void displayPatients() {
    bool found = false;

    for (int i = 0; i < SIZE; i++) {
        Patient* temp = hashTable[i];

        while (temp != NULL) {
            found = true;

            cout << "\nPatient ID: " << temp->id;
            cout << "\nName: " << temp->name;
            cout << "\nAge: " << temp->age;
            cout << "\nDisease: " << temp->disease << endl;

            temp = temp->next;
        }
    }

    if (!found) {
        cout << "No patient records available!\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n1. Register Patient";
        cout << "\n2. Update Patient";
        cout << "\n3. Discharge Patient";
        cout << "\n4. Display All Patient Records";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerPatient();
                break;

            case 2:
                updatePatient();
                break;

            case 3:
                dischargePatient();
                break;

            case 4:
                displayPatients();
                break;

            case 5:
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } 

    while (choice != 5);

    return 0;
}
