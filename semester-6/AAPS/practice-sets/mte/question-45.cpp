// Write a program to print 1 To N without loop

#include <cstdio>

class Solution
{
public:
    static void solve(int n)
    {
        if(n > 0)
        {
            solve(n-1);
            printf("%d ", n);
        }
    }
};
