// Given a sorted array, arr[] consisting of N integers, write a program to
// find the frequencies of each array element

#include <vector>
#include <cmath>

class Solution {
public:
    // Function to find the frequencies of each element in a sorted array
    static std::vector<std::pair<int, int>> solve(const std::vector<int>& arr) {
        std::vector<std::pair<int, int>> frequencies;
        size_t n = arr.size();

        if (n == 0)
            return frequencies; // Empty array

        int currentElement = arr[0];
        int count = 1;

        // Iterate through the array starting from the second element
        for (int i = 1; i < n; ++i) {
            if (arr[i] == currentElement) {
                count++; // Increment count if the element is the same as the previous one
            } else {
                // Add the frequency of the current element to the result vector
                frequencies.emplace_back(currentElement, count);
                currentElement = arr[i]; // Update current element
                count = 1; // Reset count for the new element
            }
        }

        // Add the frequency of the last element to the result vector
        frequencies.emplace_back(currentElement, count);

        return frequencies;
    }
};