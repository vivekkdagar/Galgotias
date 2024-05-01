// Implement stack with singly linked list

#include <iostream>
#include <climits>

// Node class for the singly linked list
class Node {
public:
    int data;
    Node *next;

    // Constructor to initialize node with data and next pointer
    explicit Node(int value) : data(value), next(nullptr) {}
};

// Stack class implemented with a singly linked list
class Stack {
private:
    Node *top; // Pointer to the top of the stack
public:
    // Constructor to initialize an empty stack
    Stack() : top(nullptr) {}

    // Destructor to deallocate memory
    ~Stack() {
        while (top != nullptr) {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Function to check if the stack is empty
    [[nodiscard]] bool isEmpty() const {
        return top == nullptr;
    }

    // Function to push a new element onto the stack
    void push(int value) {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return INT_MIN; // Return minimum integer value indicating an error
        }
        int poppedValue = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    // Function to return the top element of the stack without popping it
    [[nodiscard]] int peek() const {
        if (isEmpty()) {
            std::cout << "Stack is empty. No top element." << std::endl;
            return INT_MIN; // Return minimum integer value indicating an error
        }
        return top->data;
    }
};