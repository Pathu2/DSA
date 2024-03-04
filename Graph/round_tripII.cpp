#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> visited;

void dfs(int node, bool* found)
{
    visited[node] = 1;
    for (auto v : g[node])
    {
        if (visited[v] == 0)
        {
            dfs(v, found);
        }
        else if (visited[v] == 1)
        {
            (*found)=true;
            return;
        }
    }
    visited[node] = 2;
    return;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    visited.assign(n + 1, 0);
    bool found = false;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i, &found);
        }
    }

    if (!found)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
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
