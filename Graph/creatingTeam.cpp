#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> visited;
bool ex;
vector<int> parent;
vector<int> p;
void dfs(int node)
{
    visited[node]=1;
    for (auto v: g[node])
    {
        if (parent[node]==v)
        {
            continue;
        }
        
        if(visited[v]==0)
        {
            parent[v]=node;
            
            dfs(v);
            p[v]=p[parent[v]]+1;
        }
        else if(visited[v]==1)
        {  
            ex=true;
        }
        
    }
    visited[node]=2;
    
}

void solve(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    visited.assign(n+1, 0);
    parent.assign(n+1, 0);
    p.assign(n+1, 0);
    while (m--)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    

    for (int i = 1; i <= n; i++)
    {
        if (visited[i]==0)
        {
            dfs(i);
        }    
    }
    
    for (int i = 1; i <=n; i++)
    {
        cout<<"parent of "<<i<<" is "<<parent[i]<<endl;
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