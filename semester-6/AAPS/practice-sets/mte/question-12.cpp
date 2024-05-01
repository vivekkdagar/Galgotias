// Write a program to find the first occurrence of repeating character in a given
// string.

#include <string>

class Solution {
public:
    static int solve(const std::string &str) {
        int charCount[26] = {0}; // Array to store counts of each character

        // Iterate through the string and count occurrences of each character
        for (int i{0}; i < str.length(); ++i) {
            // Convert character to lowercase and calculate its index in the array
            int index = str[i] - 'a';

            // If the character is already seen, return its index
            if (charCount[index] > 0)
                return i;

            // Otherwise, mark the character as seen by incrementing its count
            charCount[index]++;
        }

        // No repeating character found
        return -1;
    }
};