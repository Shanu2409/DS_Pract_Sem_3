#include <iostream>
#include <stack>
using namespace std;

string rev(string s)
{
    int n = s.length();

    for (int i = 0; i < n / 2; i++)
        swap(s[i], s[n - i - 1]);

    return s;
}

int prec(char c)
{
    return c == '=' || c == '-' ? 1 : c == '/' || c == '*' ? 2
                                  : c == '^'               ? 3
                                                           : 0;
}

string postFix(string str)
{
    stack<char> s;
    string ans = "";
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(')
        {
            s.push(ch);
        }

        else if (ch == ')')
        {
            while (s.top() != '(')
            {
                ans = ans + s.top();
                s.pop();
            }
            s.pop();
        }

        else if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^')
        {
            if (!s.empty() && prec(s.top()) > prec(ch) && !s.top() == '(')
            {
                if (ch == '^' && s.top() == '^')
                    break;
                ans = ans + s.top();
                s.pop();
            }
            s.push(ch);
        }

        else
        {
            ans += ch;
        }
    }

    while (!s.empty())
    {
        ans = ans + s.top();
        s.pop();
    }

    return ans;
}

string preFix(string str)
{
    str = rev(str);

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            str[i] = ')';
        else if (str[i] == ')')
            str[i] = '(';
    }

    str = postFix(str);

    str = rev(str);

    return str;
}

int main()
{
    // cout << "Infix = ((A + B) - C * (D / E)) + F" << endl;

    cout << "PostFix = ";
    cout << postFix("a^b") << endl;

    // cout << "Prefix = ";
    // cout << preFix("((A + B) - C * (D / E)) + F") << endl;

    return 0;
}

/*

output :

Infix = ((A + B) - C * (D / E)) + F
PostFix = A  B+  C  D  E/*-  F+
Prefix = +*-+A  B  C  /D  E  F

*/