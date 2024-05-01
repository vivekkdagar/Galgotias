// Write a program to implement a stack using queues.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Stack {
private:
    queue<int> mainQueue;    // Main queue to act as stack
    queue<int> tempQueue;    // Temporary queue for operations requiring reordering

public:
    // Function to push an element onto the stack
    void push(int x) {
        // Move all elements from main queue to temp queue
        while (!mainQueue.empty()) {
            tempQueue.push(mainQueue.front());
            mainQueue.pop();
        }

        // Push the new element to the main queue
        mainQueue.push(x);

        // Move all elements back to main queue from temp queue
        while (!tempQueue.empty()) {
            mainQueue.push(tempQueue.front());
            tempQueue.pop();
        }
    }

    // Function to pop an element from the stack
    void pop() {
        if (mainQueue.empty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        mainQueue.pop();
    }

    // Function to print the stack
    void printStack() {
        if (mainQueue.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        // Print the elements of the stack
        vector<int> stackElements;
        while (!mainQueue.empty()) {
            stackElements.push_back(mainQueue.front());
            mainQueue.pop();
        }

        cout << "Stack: ";
        for (int i = stackElements.size() - 1; i >= 0; --i) {
            cout << stackElements[i] << " ";
            mainQueue.push(stackElements[i]); // Restore elements to main queue
        }
        cout << endl;
    }
};
