#include <iostream>
using namespace std;

void menu() {
    int choice;

    cout << "\n----- RESTAURANT MENU -----";
    cout << "\n1. Pizza";
    cout << "\n2. Burger";
    cout << "\n3. Pasta";
    cout << "\n4. Exit";

    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "You selected Pizza.\n";
        menu();
    }
    else if (choice == 2) {
        cout << "You selected Burger.\n";
        menu();
    }
    else if (choice == 3) {
        cout << "You selected Pasta.\n";
        menu();
    }
    else if (choice == 4) {
        cout << "Thank you! Visit again.\n";
        return;
    }
    else {
        cout << "Invalid choice!\n";
        menu();
    }
}

int main() {
    menu();
    return 0;
}
