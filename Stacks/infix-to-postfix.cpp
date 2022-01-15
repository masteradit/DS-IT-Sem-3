#include <iostream>

using namespace std;

#define MAX 20

class stack
{
public:
    char st_arr[50], infix[50], pfix[50];
    int top;
    stack() { top = -1; }
    void push(char symbol)
    {
        if (top == MAX - 1)
        {
            cout << "Stack is full\n";
            return;
        }
        st_arr[++top] = symbol;
    }

    char pop()
    {
        if (top == -1)
            return '#';
        else
            return (st_arr[top--]);
    }

    void read()
    {
        cout << "Enter the infix expression\n";
        cin >> infix;
    }

    int isempty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }

    void ConToPfix()
    {
        int l, precedence, p;
        char e1, e2;
        p = 0;
        for (int i = 0; infix[i] != '\0'; i++)
        {
            e1 = infix[i];
            switch (e1)
            {
            case '(':
                push(e1);
                break;
            case ')':
                while ((e2 = pop()) != '(')
                    pfix[p++] = e2;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                if (!isempty())
                {
                    precedence = prec(e1);
                    e2 = pop();
                    while (precedence <= prec(e2))
                    {
                        pfix[p++] = e2;
                        if (!isempty())
                            e2 = pop();
                        else
                            break;
                    }
                    if (precedence > prec(e2))
                        push(e2);
                }
                push(e1);
                break;
            default:
                pfix[p++] = e1;
                break;
            }
        }
        while (!isempty())
            pfix[p++] = pop();
        pfix[p] = '\0';
        cout << "The postfix expression is:" << pfix << endl;
    }

    int prec(char symbol)
    {
        switch (symbol)
        {
        case '/':
        case '*':
            return 3;
        case '+':
        case '-':
            return 2;
        case '(':
            return 0;
        default:
            return -1;
        }
    }
};

int main()
{
    char ch = 'y';
    stack s;
    while (ch == 'y')
    {
        s.read();
        s.ConToPfix();
        cout << "Do you wish to continue? y/n";
        cin >> ch;
    }
}
