#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool is_operator(char x);
bool is_operand(char x);
int priority(char x);
void InfixToPostfix(string exp);

int main()
{
    string exp;
    cout << "Enter infix: ";
    getline(cin, exp);
    InfixToPostfix(exp);
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

// 1= () , 2= ^ , 3= * or / , 4= + or -
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

void InfixToPostfix(string exp)
{
    string result = "";
    stack<char> st;

    for (size_t i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(')
            st.push(exp[i]);

        else if (exp[i] == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }

            st.pop(); // pop -> '('
        }

        // this condition provides numbers that has max 10 digits
        else if (is_operand(exp[i]))
        {
            char num[10];
            int index = 0;
            while (is_operand(exp[i]) && i != exp.length()) //
            {
                num[index] = exp[i];
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

        else if (is_operator(exp[i]))
        {
            while (!st.empty() && priority(st.top()) >= priority(exp[i]))
            {
                result += st.top();
                st.pop();
            }
            st.push(exp[i]);
        }
    }

    // pop remainging operator in the stack
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    cout << result << endl;
}