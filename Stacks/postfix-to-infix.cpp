#include <iostream>
#include <string.h>

using namespace std;

class pfix_ifix
{
public:
    char stack[25][25], infix[50];
    char pfix_exp[50];
    char op1[10], op2[10], res[20];
    int top;
    pfix_ifix()
    {
        top = -1;
    }
    void push(char a[])
    {
        strcpy(stack[++top], a);
    }

    char *pop()
    {
        return stack[top--];
    }

    void pifix()
    {
        int count = 0;
        char sym[2];
        while (pfix_exp[count] != '\0')
        {
            sym[0] = pfix_exp[count];
            sym[1] = '\0';
            if (sym[0] == '+' || sym[0] == '-' || sym[0] == '*' || sym[0] == '/' || sym[0] == '^')
            {
                strcpy(op1, pop());
                strcpy(op2, pop());
                strcpy(res, "(");
                strcat(res, op2);
                strcat(res, sym);
                strcat(res, op1);
                strcat(res, ")");
                push(res);
            }
            else
                push(sym);
            count++;
        }
        strcpy(infix, pop());
        cout << "Infix expression is:" << infix;
    }
};
int main()
{

    pfix_ifix pi;
    cout << "Enter the postfix expression:";
    gets(pi.pfix_exp);
    pi.pifix();
    return 0;
}
