#include <iostream>
#include <conio.h>
#include <stack>
#include <string>

using namespace std;

bool is_operator(char x);
bool is_operand(char x);
int priority(char x);
void InfixToPrefix(string exp);

int main()
{
    string exp;
    cout << "Enter infix: ";
    getline(cin, exp);
    InfixToPrefix(exp);
    return 0;
}

// operator = +,-,*,/,^
bool is_operator(char x)
{
    string op = "*/-+^";
    for (size_t i = 0; i < op.length(); i++)
    {
        if (op[i] == x)
            return true;
    }

    return false;
}

// operand = 1,2,3,4,5,6,7,8,9
bool is_operand(char x)
{
    string op = "0123456789";
    for (size_t i = 0; i < op.length(); i++)
    {
        if (x == op[i])
            return true;
    }

    return false;
}

//  1= ^ , 2= * or / , 3= + or -
int priority(char x)
{
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    return -1;
}

// convert infix to prefix using stack
void InfixToPrefix(string expression)
{
    string result = "";
    stack<char> st; // declare stack

    string exp2 = "";
    // reverse infix
    for (int i = expression.length() - 1; i >= 0; i--)
    {
        if (expression[i] == '(')
            exp2 += ')';
        else if (expression[i] == ')')
            exp2 += '(';
        else
            exp2 += expression[i];
    }

    // this is almost like infix to postfix
    for (size_t i = 0; i < exp2.length(); i++)
    {
        if (exp2[i] == '(')
            st.push(exp2[i]);

        else if (exp2[i] == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop(); // pop -> '('
        }

        // find operand
        else if (is_operand(exp2[i]))
        {
            char num[10];
            int index = 0;
            while (is_operand(exp2[i]) && i != exp2.length())
            {
                num[index] = exp2[i];
                i++;
                index++;
            }
            string res = "";
            for (int j = 0; j < index; j++)
            {
                res += num[j];
            }
            result += ' ';
            result += res;
            i--;
        }

        // find operator
        else if (is_operator(exp2[i]))
        {
            // this sections are diffrent from convert to postfix code
            while (!st.empty() && priority(st.top()) > priority(exp2[i]))
            {
                result += ' ';
                result += st.top();
                st.pop();
            }
            st.push(exp2[i]);
        }
    }

    // pop remaining elements from stack
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    exp2 = "";
    // reverse againg
    for (int i = result.length() - 1; i >= 0; i--)
    {
        exp2 += result[i];
    }
    cout << exp2 << endl;
}