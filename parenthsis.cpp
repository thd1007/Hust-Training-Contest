#include <bits/stdc++.h>
using namespace std;
int n;
string s;
bool areParanthesisBalanced(string expr)
{
    stack<char> s;
    char x;

    // Traversing the Expression
    for (int i=0; i<expr.length(); i++)
    {
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{')
        {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }

        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (s.empty())
            return false;

        switch (expr[i])
        {
            case ')':

                // Store the top element in a
                x = s.top();
                s.pop();
                if (x=='{' || x=='[')
                    return false;
                break;

            case '}':

                // Store the top element in b
                x = s.top();
                s.pop();
                if (x=='(' || x=='[')
                    return false;
                break;

            case ']':

                // Store the top element in c
                x = s.top();
                s.pop();
                if (x =='(' || x == '{')
                    return false;
                break;
        }
    }

    // Check Empty Stack
    return (s.empty());
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--)
    {
        cin >> s;
        cout << areParanthesisBalanced(s) << '\n';
    }
}
