/* Check whether K-th bit is set or not. Given a number N and a bit number K, 
check if Kth index bit of N is set or not. A bit is called set if it is 1. Position of
set bit '1' should be indexed starting with 0 from LSB side in binary
representation of the number. Index is starting from 0. You just need to 
return true or false.*/

class Solution {
public:
    static bool solve(int N, int K) {
        // Shift 1 to the left by K positions to create a mask
        // If the K-th bit in N is set, the result of AND operation will be non-zero
        return (N & (1 << K)) not_eq 0;
    }
};
