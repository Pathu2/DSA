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
    int N, M;
    cin>>N>>M;
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
    int sum = 0;
    for (auto v:mp)
    {
        sum=sum + v.second;
    }
    int sum_pair = 0;
    for (auto v:mp)
    {
        sum_pair = sum_pair + (v.second)*(sum-v.second);
    }
    sum_pair = sum_pair/2;
    cout<<sum_pair<<endl;
    
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}