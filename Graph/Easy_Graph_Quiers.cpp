#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> g;
vector<int> visited;

void dfs(int node, int comp)
{
    visited[node]=comp;
    for(auto v:g[node])
    {
        if (visited[v]==0)
        {
            dfs(v, comp);
        }
    }
}

void solve(){
    int Q, N, M;
    cin>>N>>M>>Q;
    g.resize(N+1);
    visited.assign(N+1, 0);
    while (M--)
    {
        int a, b;
        cin>>a>>b;
        if (a==b)
        {
            continue;
        }
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int comp = 0;
    for (int i = 1; i < N+1; i++)
    {
        if (visited[i]==0)
        {
            comp++;
            dfs(i, comp);
        }
        
    }
    map<int, int> mp;
    for (int i = 1; i < visited.size(); i++)
    {
        mp[visited[i]]++;
    }
    while (Q--)
    {
        int num;
        cin>>num;
        if (num==1)
        {
            int X;
            cin>>X;
            cout<<mp[visited[X]]<<endl;
        }
        else
        {
            int X, Y;
            cin>>X>>Y;
            if (visited[X]==visited[Y])
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
            
        }
        
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