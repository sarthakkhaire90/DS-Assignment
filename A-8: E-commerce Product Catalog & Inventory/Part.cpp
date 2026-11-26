#include <iostream>
#include <string>
using namespace std;

struct Product {
    int id;
    string name;
    float price;
    int quantity;
    Product* next;
};

const int SIZE = 10;
Product* hashTable[SIZE] = {NULL};

int hashFunction(int id) {
    return id % SIZE;
}

void addProduct() {
    Product* newProduct = new Product;

    cout << "Enter Product ID: ";
    cin >> newProduct->id;

    int index = hashFunction(newProduct->id);
    Product* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->id == newProduct->id) {
            cout << "Product ID already exists!\n";
            delete newProduct;
            return;
        }
        temp = temp->next;
    }

    cout << "Enter Product Name: ";
    cin.ignore();
    getline(cin, newProduct->name);

    cout << "Enter Product Price: ";
    cin >> newProduct->price;

    cout << "Enter Product Quantity: ";
    cin >> newProduct->quantity;

    newProduct->next = hashTable[index];
    hashTable[index] = newProduct;

    cout << "Product added successfully!\n";
}

void updateProduct() {
    int id;

    cout << "Enter Product ID: ";
    cin >> id;

    int index = hashFunction(id);
    Product* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Enter New Product Name: ";
            cin.ignore();
            getline(cin, temp->name);

            cout << "Enter New Price: ";
            cin >> temp->price;

            cout << "Enter New Quantity: ";
            cin >> temp->quantity;

            cout << "Product updated successfully!\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Product not found!\n";
}

void removeProduct() {
    int id;

    cout << "Enter Product ID: ";
    cin >> id;

    int index = hashFunction(id);

    Product* temp = hashTable[index];
    Product* prev = NULL;

    while (temp != NULL) {
        if (temp->id == id) {
            if (prev == NULL) {
                hashTable[index] = temp->next;
            } else {
                prev->next = temp->next;
            }

            delete temp;
            cout << "Product removed successfully!\n";
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Product not found!\n";
}

void displayProducts() {
    bool found = false;

    for (int i = 0; i < SIZE; i++) {
        Product* temp = hashTable[i];

        while (temp != NULL) {
            found = true;

            cout << "\nProduct ID: " << temp->id;
            cout << "\nProduct Name: " << temp->name;
            cout << "\nPrice: " << temp->price;
            cout << "\nQuantity: " << temp->quantity << endl;

            temp = temp->next;
        }
    }

    if (!found) {
        cout << "No products available!\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Product";
        cout << "\n2. Update Product";
        cout << "\n3. Remove Product";
        cout << "\n4. Display All Products";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct();
                break;

            case 2:
                updateProduct();
                break;

            case 3:
                removeProduct();
                break;

            case 4:
                displayProducts();
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
