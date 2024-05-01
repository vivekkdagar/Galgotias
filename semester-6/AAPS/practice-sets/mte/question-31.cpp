// Given an integer k and a queue of integers,
// write a program to reverse the order of the first k elements of the queue,
// leaving the other elements in the same relative order.

#include <queue>
#include <deque>

class Solution {
public:
    static void solve(std::queue<int> &q, int k) {
        std::deque<int> d;

        // Dequeue the first k elements of the queue and push
        // them onto a deque
        for (int i = 0; i < k; i++) {
            d.push_front(q.front());
            q.pop();
        }

        // Pop the elements from the deque and enqueue them back
        // into the queue
        while (!d.empty()) {
            q.push(d.front());
            d.pop_front();
        }

        // Dequeue the remaining elements from the queue and
        // enqueue them back into the queue
        for (int i = 0; i < q.size() - k; i++) {
            q.push(q.front());
            q.pop();
        }
    }
};