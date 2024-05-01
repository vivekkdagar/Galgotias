// Write a program to find Smallest Positive missing number. You are given an 
// array arr[] of N integers. The task is to find the smallest positive number missing
// from the array. Positive number starts from 1

#include <vector>
#include <cmath>

class Solution {

public:
    static int solve(std::vector<int> &arr) {
        size_t n = arr.size();

        // Loop to traverse the whole array
        for (int i = 0; i < n; i++) {

            // Loop to check boundary
            // condition and for swapping
            while (arr[i] >= 1 && arr[i] <= n
                   && arr[i] != arr[arr[i] - 1]) {
                std::swap(arr[i], arr[arr[i] - 1]);
            }
        }

        // Checking any element which
        // is not equal to i+1
        for (int i = 0; i < n; i++)
            if (arr[i] not_eq i + 1)
                return i + 1;

        // Nothing is present return last index
        return n + 1;
    }
};