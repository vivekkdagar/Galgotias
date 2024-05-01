// Given a non-negative integer N. The task is to check if N is a power of 2. More 
// formally, check if N can be expressed as 2x for some integer x. Return true if N
// is power of 2 else return false.

#include <cmath>

class Solution {
public:
    static bool solve(int n) {
        double log = log2(n);
        return (log - floor(log)) == 0;
    }

    // Method2: without libraries
    static bool isPowerOfTwo(int n) {
        // A number is a power of 2 if it has only one bit set to 1.
        // Use bitwise AND to check if only one bit is set.
        // For example, 8 (binary: 1000) is a power of 2, while 9 (binary: 1001) is not.

        // Return true if n is greater than 0 and n has only one bit set to 1.
        return (n > 0) && ((n & (n - 1)) == 0);
    }
};
