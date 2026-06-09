#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
int main()
{

        string expr;
        stack<double> numbers;
        getline(cin, expr);
        for (int i = 0; i < expr.size(); i++)
        {
            if (expr[i] == ' ')
                continue;
            if (isdigit(expr[i]))
            {
                double num = 0;
                do
                {
                    num *= 10;
                    num += expr[i] - '0';
                    i++;
                } while (i < expr.size() && isdigit(expr[i]));
                i--;
                numbers.push(num);
            }
            else
            {
                double op2 = numbers.top();
                numbers.pop();
                double op1 = numbers.top();
                numbers.pop();
                switch (expr[i])
                {
                case '+': numbers.push(op1 + op2); break;
                case '-': numbers.push(op1 - op2); break;
                case '*': numbers.push(op1 * op2); break;
                case '/': numbers.push(op1 / op2); break;
                case '%': numbers.push((int)op1 % (int)op2); break;
                case '^': numbers.push(pow(op1,op2)); break;
                }
            }
        }
        cout.precision(1);
        cout.setf(cout.showpoint);
        cout << fixed << numbers.top() << endl;

    
}
