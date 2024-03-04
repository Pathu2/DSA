#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int Q;
    cin >> Q;
    string s;
    int t;
    queue<int> q;
    while (Q--)
    {
        cin >> s;
        if (s == "add")
        {
            cin >> t;
            q.push(t);
        }
        else if (s == "remove")
        {
            if (q.size() != 0)
            {
                q.pop();
            }
        }
        else if (s == "print")
        {
            if (q.size() == 0)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << q.front() << endl;
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}