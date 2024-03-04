#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;
vector<int> par, depth;
map<int, int> mp;
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

void dfs1(int node, int parent, int dp, int dist, int i)
{
    par[node] = parent;
    depth[node]=dp;
    for (auto v : t[node])
    {
        if (v != parent)
        {
            if (depth[v]==dist)
            {
                mp[i]++;
            }
            dfs1(v, node, dp+1, dist, i);
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
    int dist = 0;
    int node = mx;
    while (dist < depth[mx] / 2)
    {
        node = par[node];
        dist++;
    }
    if(depth[mx]%2==0)
    {
        int center = node;
        for(int i = 0; i<t[node].size();i++)
        {
            cout<<t[node][i]<<" ";
            dfs1(t[node][i], center, 0, (depth[mx]/2)-1, i);
        }
    }
    cout<<endl;
    for(auto v : mp)
    {
        cout<<v.first<<" "<<v.second<<endl;
    }
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