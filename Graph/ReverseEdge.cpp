#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> g;
vector<vector<int>> g_r;
vector<int> indeg;
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    g_r.resize(n+1);
    indeg.assign(n+1,0);
    while (m--)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g_r[b].push_back(a);
        indeg[b]++;
    }
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t; cin>>t; while(t--){
        solve();
    }
    return 0;
}