#include<bits/stdc++.h>
using namespace std;
#define int long long
struct UnionFind{
    vector<int> par, rank;
    void init(int n)
    {
        par.resize(n+1);
        for(int i =0;i<=n;i++)
        {
            par[i]=i;
        }
        rank.assign(n+1, 1);
    }

    int find(int x)
    {
        if(par[x]==x)
        {
            return x;
        }
        else par[x]=find(par[x]);
    }

    void merge(int rootx, int rooty)
    {
        if(rank[rootx]>=rank[rooty])
        {
            par[rooty]=rootx;
            rank[rootx]= rank[rootx] + rank[rooty];
        }
        else
        {
            par[rootx]=rooty;
            rank[rooty]= rank[rooty] + rank[rootx];
        }
    }
};
void solve(){
    int n, m;
    cin>>n>>m;
    priority_queue<pair<int, pair<int, int>>> pq;
    if(m<(n-1))
    {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    int req = m;
    while (req--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        pq.push({-c, {a, b}});
    }

    int ct=0;
    UnionFind check;
    check.init(n);
    int sum =0;
    for(int i = 0; i <m ;i++)
    {
        if(ct==n-1)
        {
            break;
        }
        else
        {
            auto v = pq.top();
            int rootx = check.find(v.second.first);
            int rooty = check.find(v.second.second);
            pq.pop();
            if(rootx==rooty)
            {
                /*Means they will form a cycle if connected by egde*/
                continue;
            }
            else
            {
                check.merge(rootx, rooty);
                sum = sum + (-v.first);
                ct++;
            }
        }
    }
    if(ct!=n-1)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        cout<<sum<<endl;
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