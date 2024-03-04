#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> parent, depth, no_of_childs, subtreesz;
void dfs(int node, int par, int dp)
{
    parent[node] = par;
    depth[node]  = dp;
    subtreesz[node]=1;
    for(auto v: g[node])
    {
        if(v!=par)
        {
            no_of_childs[node]++;
            dfs(v, node, dp+1);
            subtreesz[node] = subtreesz[v] + subtreesz[node];
        }
    }
}

void solve(){
    int n;
    cin>>n;
    g.resize(n+1);
    parent.resize(n+1);
    depth.assign(n+1, 0);
    no_of_childs.assign(n+1, 0);
    subtreesz.assign(n+1, 0);
    for(int i = 0;i<=n;i++)
    {
        parent[i]=i;
    }
    for(int i =1;i<=n-1;i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0, 0);
    for(int i =1;i<=n;i++)
    {
        cout<<subtreesz[i]<<" ";
    }
    cout<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}