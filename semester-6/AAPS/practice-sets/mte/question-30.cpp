// Write a program to print all the LEADERS in the array.
// An element is a leader if it is greater than all the elements to its right side.
// And	the rightmost element is always a leader.

#include <iostream>
#include <vector>

class Solution {
public:
    static void solve(const std::vector<int> &arr) {
        size_t n = arr.size();
        int max_from_right = arr[n - 1]; // Rightmost element is always a leader
        std::cout << "Leaders: " << max_from_right << " ";

        // Traverse the array from right to left
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > max_from_right) {
                max_from_right = arr[i];
                std::cout << max_from_right << " ";
            }
        }
        std::cout << std::endl;
    }
};