#include <iostream>
using namespace std;

int main() {
    int queue[5];
    int front = 0;
    int rear = 0;

    cout << "Enter 5 customer Order Numbers:\n";

    for (int i = 0; i < 5; i++) {
        cout << "Enter Order Number " << i + 1 << ": ";
        cin >> queue[rear];
        rear++;
    }

    cout << "\nCustomer Orders in Queue:\n";

    while (front < rear) {
        cout << "Order Number: " << queue[front] << endl;
        front++;
    }

    return 0;
}
