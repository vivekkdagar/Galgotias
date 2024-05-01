// Implement circular linked list

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    explicit Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node *head;
public:
    CircularLinkedList() : head(nullptr) {}

    ~CircularLinkedList() {
        if (head not_eq nullptr) {
            Node *current = head->next;
            while (current not_eq head) {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
            delete head;
        }
    }

    // Function to insert a node at a given position in the circular linked list
    void insert(int value, unsigned int position) {
        Node *newNode = new Node(value);

        // If list is empty or position is 1, insert at the beginning
        if (not head or position <= 1) {
            if (not head) {
                head = newNode;
                head->next = head;
            } else {
                Node *last = head;
                while (last->next not_eq head) {
                    last = last->next;
                }
                newNode->next = head;
                head = newNode;
                last->next = head;
            }
        } else {
            Node *temp = head;
            for (int i = 1; i < position - 1 && temp->next not_eq head; ++i) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Function to delete a node from the circular linked list
    void remove(int position) {
        if (not head) {
            cout << "Circular linked list is empty." << endl;
            return;
        }

        // If position is 1, delete from the beginning
        if (position == 1) {
            Node *temp = head;
            if (head->next == head) {
                head = nullptr;
            } else {
                Node *last = head;
                while (last->next not_eq head) {
                    last = last->next;
                }
                head = head->next;
                last->next = head;
            }
            delete temp;
        } else {
            Node *temp = head;
            for (int i{1}; i < position - 1 && temp->next not_eq head; ++i) {
                temp = temp->next;
            }
            if (temp->next == head) {
                cout << "Position exceeds the length of the circular linked list." << endl;
                return;
            }
            Node *toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }
    }

    // Function to print the circular linked list
    void printList() {
        if (not head) {
            cout << "Circular linked list is empty." << endl;
            return;
        }
        Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp not_eq head);
        cout << endl;
    }

    // Function to calculate the length of the circular linked list
    int length() {
        if (not head) return 0;

        int count{0};
        Node *temp{head};

        do {
            count++;
            temp = temp->next;
        } while (temp not_eq head);

        return count;
    }
};