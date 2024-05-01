// Write a program to implement queue using stacks.

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Queue {
private:
    stack<int> inbox;   // For enqueue operation
    stack<int> outbox;  // For dequeue operation
    vector<int> printBuffer;  // For printing queue elements

public:
    // Function to enqueue an element into the queue
    void enqueue(int value) {
        inbox.push(value);
        printBuffer.push_back(value); // Update print buffer
    }

    // Function to dequeue an element from the queue
    int dequeue() {
        if (outbox.empty()) {
            // Move elements from inbox to outbox if outbox is empty
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }

        if (outbox.empty()) {
            // Queue is empty
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Return default value indicating an error
        }

        int frontValue = outbox.top();
        outbox.pop();
        printBuffer.erase(printBuffer.begin()); // Update print buffer
        return frontValue;
    }

    // Function to print the queue elements
    void print() const {
        cout << "Queue: ";
        for (int value: printBuffer) {
            cout << value << " ";
        }
        cout << endl;
    }
};