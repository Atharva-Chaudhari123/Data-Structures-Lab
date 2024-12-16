#include <iostream>
#define MAX 5 // Maximum number of orders the parlor can accept
using namespace std;

class PizzaParlor {
    int front, rear;
    int orders[MAX]; // Array to store the orders

public:
    PizzaParlor() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (rear + 1 == front);
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to add an order
    void addOrder(int orderID) {
        if (isFull()) {
            cout << "Order queue is full! Cannot accept more orders.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0; // Initialize front and rear for the first order
        } else {
            rear = (rear + 1) % MAX; // Move rear to the next position (circularly)
        }

        orders[rear] = orderID;
        cout << "Order " << orderID << " added successfully.\n";
    }

    // Function to serve an order
    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve!\n";
            return;
        }

        cout << "Order " << orders[front] << " served.\n";

        if (front == rear) {
            // Reset the queue when the last order is served
            front = rear = -1;
        } else {
            front = (front + 1) % MAX; // Move front to the next position (circularly)
        }
    }

    // Function to display current orders in the queue
    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders in the queue.\n";
            return;
        }

        cout << "Current orders in the queue: ";
        int i = front;
        while (true) {
            cout << orders[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX; // Move to the next position (circularly)
        }
        cout << endl;
    }
};

int main() {
    PizzaParlor parlor;
    int choice, orderID;

    do {
        cout << "\nPizza Parlor Order Management\n";
        cout << "1. Add Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Order ID: ";
            cin >> orderID;
            parlor.addOrder(orderID);
            break;
        case 2:
            parlor.serveOrder();
            break;
        case 3:
            parlor.displayOrders();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
