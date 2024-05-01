// Given a string S of lowercase alphabets, write a program to check if string is
// isogram or not

#include <string>

class Solution {
public:
    static bool solve(const std::string &str) {
        bool seen[26] = {false}; // Array to keep track of occurrence of each alphabet

        for (char ch: str) {
            // Convert character to lowercase for indexing the array
            char lowercaseCh = tolower(ch);

            // If the character is already seen, it's not an isogram
            if (seen[lowercaseCh - 'a'])
                return false;

            // Mark the character as seen
            seen[lowercaseCh - 'a'] = true;
        }

        // If no repeating characters were found, it's an isogram
        return true;
    }
};