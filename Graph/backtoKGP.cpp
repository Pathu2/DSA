#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
vector<vector<pair<int, int>>> g;
vector<int> r, d, mi, mx;

void bfs()
{
    r[1] = 1;
    d[1] = 0;
    mi[1] = 0;

    priority_queue<pair<int, int>> q;
    q.push({0, 1});

    while(!q.empty())
    {
        int nn = q.top().second;
        q.pop();

        for(auto [a, b]: g[nn])
        {
            if(d[])
        }
    }
}

void solve(){
    cin >> n >> m;
    g = vector<vector<pair<int, int>>>(n+1); 
    r = mx = vector<int>(n+1, 0);
    d = mi = vector<int>(n+1, 1e18);

    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t; cin>>t; while(t--){
        solve();
    }
    return 0;
}