// Implement queue with singly linked list

#include <bits/stdc++.h>

using namespace std;

struct QNode {
    int data;
    QNode *next;

    explicit QNode(int d) {
        data = d;
        next = nullptr;
    }
};

struct Queue {
    QNode *front;
    QNode *rear;

    Queue() {
        front = rear = nullptr;
    }

    void enQueue(int x) {
        auto *temp = new QNode(x);
        if (rear == nullptr) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void deQueue() {
        if (front == nullptr)
            return;
        QNode *temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
    }

    // Overloaded operator to print the queue
    friend ostream &operator<<(ostream &os, const Queue &queue) {
        QNode *temp = queue.front;
        while (temp not_eq nullptr) {
            os << temp->data << " ";
            temp = temp->next;
        }
        return os;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    int getFront() {
        if (front not_eq nullptr)
            return front->data;
        return INT_MIN; // Return some default value indicating queue is empty
    }

    int getBack() {
        if (this->rear not_eq nullptr)
            return this->rear->data;
        return INT_MIN; // Return some default value indicating queue is empty
    }
};