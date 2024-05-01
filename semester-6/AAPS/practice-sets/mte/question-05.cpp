// Write a program to find max and second max of array.

#include <vector>
#include <cmath>
#include <climits>

class Solution {
public:
    static std::pair<int, int> solve(const std::vector<int> &arr) {
        size_t n = arr.size();
        if (n < 2)
            return std::make_pair(-1, -1);

        int maxNum = INT_MIN;
        int secondMax = INT_MIN;

        // Find the maximum element in the array
        for (int num: arr) {
            if (num > maxNum) {
                secondMax = maxNum;
                maxNum = num;
            } else if (num > secondMax and num < maxNum)
                secondMax = num;
        }

        // If there's no second maximum element, set it to -1
        if (secondMax == INT_MIN)
            secondMax = -1;

        return std::make_pair(maxNum, secondMax);
    }
};