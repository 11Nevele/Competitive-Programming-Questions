#include <iostream>
#include <stack>
#include<cmath>
#include <string>
using namespace std;
int main()
{
    string expr;
    stack<float> numbers;
    getline(cin, expr);//input the expression
    for (int i = 0; i < expr.size(); i++)
    {
        if (expr[i] == ' ')
            continue;
        if (isdigit(expr[i]))
        {
            float num = 0;
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
            float n1, n2;
            n2 = numbers.top();
            numbers.pop();
            n1 = numbers.top();
            numbers.pop();
            switch (expr[i])
            {
            case '+': numbers.push(n1 + n2); break;
            case '-': numbers.push(n1 - n2); break;
            case '*': numbers.push(n1 * n2); break;
            case '/': numbers.push(n1 / n2); break;
            case '%': numbers.push((int)n1 % (int)n2); break;
            case '^': numbers.push(pow(n1,n2)); break;
            }
        }
    }
    cout.precision(1);
    cout.setf(cout.showpoint);
    cout << fixed << numbers.top() << endl;
}
//5 5 + 6 * 8 -
//10 6 * 8 -
//60 8 -
//60 - 8 = 52