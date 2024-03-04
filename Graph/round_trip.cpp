#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> g;

vector<int> vis;
vector<int> parent;
void dfs(int node, int* no_of_cycles)
{
    
    vis[node]=1;
    for (auto v:g[node])
    {
        if (parent[node]==v)
        {
            continue;
        }parent[v]=node;
        if (vis[v]==0)
        {
            
            dfs(v, no_of_cycles);
        }
        else if(vis[v]==1)
        {
            (*no_of_cycles)++;
        }
    }
    
    return;
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1, 0);
    parent.assign(n+1,-1);
    int no_of_cycles = 0;
    while (m--)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i]==0)
        {
            dfs(i, &no_of_cycles);
        }
    }
    
    
    if (no_of_cycles==0)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
        cout<<no_of_cycles<<endl;
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