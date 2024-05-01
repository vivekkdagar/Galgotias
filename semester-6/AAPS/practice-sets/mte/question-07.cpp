// Write a program to merge two sorted linked list.

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static ListNode *solve(ListNode *l1, ListNode *l2) {
        // Create a dummy node to serve as the head of the merged list
        auto *dummy = new ListNode(0);
        ListNode *current = dummy;

        // Traverse both lists simultaneously and merge them
        while (l1 not_eq nullptr and l2 not_eq nullptr) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        // Attach the remaining elements of either list, if any
        current->next = (l1) ? l1 : l2;

        // Return the merged list (excluding the dummy node)
        return dummy->next;
    }
};

/*
void printList(ListNode *head) {
    ListNode *current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
} */