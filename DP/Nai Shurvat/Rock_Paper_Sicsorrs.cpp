#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
vector<char> init;
set<vector<char>> kya;
int mx;

int check(vector<char> v)
{
    int wins = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'P')
        {
            if (init[i] == 'S')
            {
                wins++;
            }
        }
        else if (s[i] == 'R')
        {
            if (init[i] == 'P')
            {
                wins++;
            }
        }
        else
        {
            if (init[i] == 'R')
            {
                wins++;
            }
        }
    }
    return wins;
}

void max_win(int level, char prev, int k)
{
    // basecase
    if (level == n)
    {
        int wins = check(init);
        if (mx < wins)
        {
            kya.clear();
            mx = wins;
            kya.insert(init);
        }
        else if (mx == wins)
        {
            kya.insert(init);
        }
        return;
    }
    // compute
    if (k > 0)
    {
        // either change it
        if (prev == 'P')
        {
            init.push_back('R');
            max_win(level + 1, 'R', k - 1);
            init.pop_back();
            init.push_back('S');
            max_win(level + 1, 'S', k - 1);
            init.pop_back();
        }
        else if (prev == 'R')
        {
            init.push_back('P');
            max_win(level + 1, 'P', k - 1);
            init.pop_back();
            init.push_back('S');
            max_win(level + 1, 'S', k - 1);
            init.pop_back();
        }
        else
        {
            init.push_back('P');
            max_win(level + 1, 'P', k - 1);
            init.pop_back();
            init.push_back('S');
            max_win(level + 1, 'S', k - 1);
            init.pop_back();
        }

        // or dont change it
        init.push_back(prev);
        max_win(level + 1, prev, k);
        init.pop_back();
    }
    else
    {
        init.push_back(prev);
        max_win(level + 1, prev, k);
        init.pop_back();
    }
}

void solve()
{
    cin >> n >> k;
    cin >> s;
    mx = 0;
    kya.clear();
    // getting the first letter
    init.push_back('P');
    max_win(1, 'P', k);
    init.pop_back();

    init.push_back('R');
    max_win(1, 'R', k);
    init.pop_back();

    init.push_back('S');
    max_win(1, 'S', k);
    init.pop_back();

    cout << mx << endl;
    for (char c : (*kya.begin()))
    {
        cout << c;
    }
    cout<<endl;
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