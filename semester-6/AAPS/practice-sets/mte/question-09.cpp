// Write a program to evaluate a postfix expression

#include <stack>
#include <string>
#include <cmath>
#include <stdexcept>

class Solution {
public:
    static double solve(const std::string &expression) {
        std::stack<double> operands;

        for (char ch: expression) {
            if (isdigit(ch)) {
                // If character is a digit, convert it to a number and push onto stack
                operands.push(ch - '0');
            } else {
                // If character is an operator, pop operands from stack, apply operator, and push result back onto stack
                double operand2 = operands.top();
                operands.pop();
                double operand1 = operands.top();
                operands.pop();

                switch (ch) {
                    case '+':
                        operands.push(operand1 + operand2);
                        break;
                    case '-':
                        operands.push(operand1 - operand2);
                        break;
                    case '*':
                        operands.push(operand1 * operand2);
                        break;
                    case '/':
                        operands.push(operand1 / operand2);
                        break;
                    case '^':
                        operands.push(pow(operand1, operand2));
                        break;
                    case '%':
                        operands.push(fmod(operand1, operand2));
                        break;
                    default:
                        throw std::invalid_argument(std::string("Invalid operator: " + std::string(1, ch)));
                }
            }
        }

        // The result is the only element left in the stack
        return operands.top();
    }
};