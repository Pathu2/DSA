#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> visited;
vector<int> parent;
void dfs(int node, int num_of_com)
{
    visited[node]=num_of_com;
    for (auto v: g[node])
    {
        if (parent[node]==v)
        {
            continue;
        }
        parent[v]=node;
        if (visited[v]==0)
        {
            dfs(v, num_of_com);
        }
    }
    return;
}

void solve(){
    int n, m;
    cin>>n>>m;
    g.resize(n+1);
    visited.assign(n+1,0);
    parent.assign(n+1,0);
    while (m--)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int num_of_comp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i]==0)
        {
            num_of_comp++;
            dfs(i, num_of_comp);
        }
        
    }
    cout<<num_of_comp-1<<endl;
    

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}