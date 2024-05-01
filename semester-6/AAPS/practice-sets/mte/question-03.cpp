// Write a program to Count Total Digits in a Number using recursion. You are 
// given a number n. You need to find the count of digits in n

class Solution {
public:
    static int solve(int n) {
        if (n == 0)
            return 0;
        return solve(n / 10) + 1;
    };
};
