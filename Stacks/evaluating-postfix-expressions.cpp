#include <iostream>
#include <math.h>
#include <ctype.h>

using namespace std;

class postfix_eval
{
public:
    int st[50], top, item;
    char pfix[50];
    postfix_eval() { top = -1; }
    void push(int item)
    {
        st[++top] = item;
    }
    int pop()
    {
        return st[top--];
    }

    int operation(int a, int b, char opr)
    {
        switch (opr)
        {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return pow(a, b);
        default:
            return 0;
        }
    }

    int calpfix()
    {
        int index = 0, op1, op2;
        while (pfix[index] != '\0')
        {
            if (isdigit(pfix[index]))
                push(pfix[index] - '0'); // if 9 has ascii value 57
                                         //subtracting by 48(of '0')
                    //gives 9 as the result
            else
            {
                op1 = pop();
                op2 = pop();
                int res = operation(op2, op1, pfix[index]);
                push(res);
            }
            index++;
        }
        return pop();
    }
};
int main()
{
    postfix_eval pe;
    cout << "Enter the postfix expression\n";
    cin >> pe.pfix;
    int res = pe.calpfix();
    cout << "Result:" << res;
    return 0;
}
