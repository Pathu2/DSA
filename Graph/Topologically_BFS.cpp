#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> indeg;
vector<int> topo;
void order(int node)
{
    queue<int> q;
    for (auto zero: indeg)
    {
        if (zero==0)
        {
            q.push(zero);
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        topo.push_back(cur);
        q.pop();
        for (auto v: g[cur])
        {
            indeg[v]--;
            if (indeg[v]==0)
            {
                q.push(v);
            }
        }
    }

    
    
}

void solve(){
    int n, m;
    cin>>n>>m;
    g.resize(n+1);
    indeg.assign(n+1, 0);
    while (m--)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        indeg[b]++;
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