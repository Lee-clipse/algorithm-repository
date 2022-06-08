#include <iostream>
#include <stack>

using namespace std;


void Solve ()
{
    string S, F;
    getline(cin, S);

    int idx = 0;
    char c = S[idx];
    while (c != '\0')
    {
        c = S[idx];

        if (c == '<')
        {
            F += c;

            while (c != '>')
            {
                c = S[++idx];
                F += c;
            }

            idx++;
        }

        else
        {
            stack <char> s;

            while (c != ' ' && c != '\0' && c != '<')
            {
                s.push(c);
                c = S[++idx];
            }

            while (!s.empty())
            {
                F += s.top();
                s.pop();
            }

            if (c == ' ')
            {
                F += c;
                idx++;
            }
        }

    }

    cout << F;
}

int main ()
{
    Solve();

    return 0;
}
