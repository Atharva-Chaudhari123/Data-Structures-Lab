#include <iostream>
using namespace std;

#define SIZE 5  // Maximum size of the deque

class Deque {
    int arr[SIZE];
    int front, rear;

public:
    // Constructor to initialize front and rear
    Deque() {
        front = -1;
        rear = -1;
    }

    // Check if deque is full
    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    // Check if deque is empty
    bool isEmpty() {
        return front == -1;
    }

    // Add element to the front
    void insertFront(int data) {
        if (isFull()) {
            cout << "Deque is full!" << endl;
            return;
        }

        // First element
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else if (front == 0) {  // Wrap around
            front = SIZE - 1;
        } else {
            front--;
        }

        arr[front] = data;
        cout << data << " added at front." << endl;
    }

    // Add element to the rear
    void insertRear(int data) {
        if (isFull()) {
            cout << "Deque is full!" << endl;
            return;
        }

        // First element
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else if (rear == SIZE - 1) {  // Wrap around
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = data;
        cout << data << " added at rear." << endl;
    }

    // Delete element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }

        cout << arr[front] << " removed from front." << endl;

        // Single element
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == SIZE - 1) {  // Wrap around
            front = 0;
        } else {
            front++;
        }
    }

    // Delete element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }

        cout << arr[rear] << " removed from rear." << endl;

        // Single element
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {  // Wrap around
            rear = SIZE - 1;
        } else {
            rear--;
        }
    }

    // Display the contents of the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }

        cout << "Deque elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

// Main function to test the Deque
int main() {
    Deque dq;

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertRear(30);
    dq.insertFront(2);  // Deque full

    dq.display();

    dq.deleteFront();
    dq.deleteRear();

    dq.display();

    dq.insertFront(15);
    dq.display();

    return 0;
}
