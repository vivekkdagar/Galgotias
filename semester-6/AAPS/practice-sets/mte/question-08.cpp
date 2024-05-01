// Write a program to detect loop in linked list

class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize node with data and next pointer
    explicit Node(int value) : data(value), next(nullptr) {}
};

class Solution {
public:
    static bool solve(Node* head) {
        if (head == nullptr or head->next == nullptr)
            return false; // No loop if list is empty or has only one node

        Node* slowPtr = head; // Slow pointer moves one step at a time
        Node* fastPtr = head; // Fast pointer moves two steps at a time

        // Move pointers until they meet or reach the end of the list
        while (fastPtr != nullptr and fastPtr->next != nullptr) {
            slowPtr = slowPtr->next; // Move slow pointer one step
            fastPtr = fastPtr->next->next; // Move fast pointer two steps

            // If pointers meet, there is a loop
            if (slowPtr == fastPtr)
                return true;
        }

        // If fast pointer reaches the end of the list, there is no loop
        return false;
    }
};