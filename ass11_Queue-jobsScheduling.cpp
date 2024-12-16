#include <iostream>
#include <string>
using namespace std;

const int MAX = 10; // Maximum number of jobs in the queue

class JobQueue {
    string jobs[MAX];
    int front, rear;

public:
    JobQueue() : front(-1), rear(-1) {}

    // Function to add a job to the queue
    void addJob(const string& job) {
        if (rear == MAX - 1) {
            cout << "Queue is full. Cannot add job.\n";
            return;
        }

        if (front == -1) front = 0; // Initialize front on first job

        jobs[++rear] = job;
        cout << "Job added: " << job << endl;
    }

    // Function to delete a job from the queue
    void deleteJob() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty. Cannot delete job.\n";
            return;
        }

        cout << "Job deleted: " << jobs[front++] << endl;

        // Reset front and rear if queue becomes empty
        if (front > rear) {
            front = rear = -1;
        }
    }

    // Function to display the current jobs in the queue
    void displayQueue() const {
        if (front == -1 || front > rear) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Current jobs in queue: ";
        for (int i = front; i <= rear; i++) {
            cout << jobs[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    JobQueue queue;
    int choice;
    string job;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter job name: ";
            cin.ignore(); // Clear the newline character from input buffer
            getline(cin, job);
            queue.addJob(job);
            break;
        case 2:
            queue.deleteJob();
            break;
        case 3:
            queue.displayQueue();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
