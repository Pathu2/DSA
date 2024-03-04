#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;
vector<int> par, depth;
int mx;
void dfs(int node, int parent)
{
    par[node] = parent;
    for (auto v : t[node])
    {
        if (v != parent)
        {
            depth[v] = depth[node] + 1;
            if (depth[v] > depth[mx])
            {
                mx = v;
            }
            dfs(v, node);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    t.resize(n + 1);
    depth.assign(n + 1, 0);
    par.resize(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        par[i] = i;
    }
    int m = n - 1;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    mx = 1;
    dfs(1, 1);

    // got the max depth node mx from the node 1
    depth.assign(n + 1, 0);
    for (int i = 0; i < n + 1; i++)
    {
        par[i] = i;
    }

    dfs(mx, mx);
    cout << "Parent array is:  ";
    for (auto v : par)
    {
        cout << v << " ";
    }
    cout << endl
         << mx << " " << depth[mx] << endl;
    // depth of mx will give me the length of the diameter
    // now to find the center i have to travel till d/2 distance.....
    // In the question we have been said that we have to print -1 in case we find the mutliple centers

    cout << endl;
    int dist = 0;
    int node = mx;
    while (dist < depth[mx] / 2)
    {
        node = par[node];
        dist++;
    }
    cout << node << endl;
    if(depth[mx]%2!=0)
    {
        cout<<par[node]<<endl;
    }
    return;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}