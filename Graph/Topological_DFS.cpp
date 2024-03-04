#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> visited;
vector<int> topo;
void dfs(int node)
{
    visited[node] = 1;
    for (auto v: g[node])
    {
        if (visited[v]==0)
        {
            dfs(v);
        }

    }
    topo.push_back(node);
}

void solve(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    visited.assign(n+1, 0);
    while (m--)
    {
        int a, b;
        cin>>a>>b;
    }
    for (int i = 1; i <=n; i++)
    {
        dfs(i);
    }
    reverse(topo.begin(), topo.end());
    for (auto node: topo)
    {
        cout<<node<<endl;
    }
    
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}